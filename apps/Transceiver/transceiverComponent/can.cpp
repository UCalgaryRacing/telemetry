// Copyright Schulich Racing, FSAE
// Written by Justin Tijunelis and Jon Mulyk

#include "can.hpp"
#include <iostream>
#include <iomanip>

CanBus::CanBus(std::vector<Sensor> sensors) {
	// Get the callback frequency, create the sensor map, and initialize the buffer
	unsigned int highestFrequency = 0;
	for (unsigned int i = 0; i < sensors.size(); ++i) {
		if (sensors[i].traits["frequency"] > highestFrequency) {
			highestFrequency = sensors[i].traits["frequency"];
		}
		this->_sensorSmallIdMap.emplace(sensors[i].traits["smallId"], sensors[i]); 
		if (this->_sensorCanIdMap.find(sensors[i].traits["canId"]) != this->_sensorCanIdMap.end()) {
			this->_sensorCanIdMap[sensors[i].traits["canId"]].push_back(sensors[i]);
		} else {
			this->_sensorCanIdMap.emplace(sensors[i].traits["canId"], std::vector<Sensor>{sensors[i]}); 
		}
		this->_canBuffer[sensors[i].traits["smallId"]] = sensors[i].getVariant();
	}
	this->_frequency = highestFrequency;
}

bool CanBus::initialize() {
	// Attempt to open the CAN socket
	struct ifreq ifr;
	struct sockaddr_can addr;
	int sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (sock < 0) return false;
	addr.can_family = AF_CAN;
	strcpy(ifr.ifr_name, "can0");
	if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
		return false;
	}
	addr.can_ifindex = ifr.ifr_ifindex;
	fcntl(sock, F_SETFL, O_NONBLOCK);
	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		return false;
	}

	// Set the can socket and return success
	this->_canSocket = sock;
	return true;
}

bool CanBus::engineStarted() {
	// If the RPM goes over 1000, the engine is surely on...
	// if (this->_canBuffer.find(25) != this->_canBuffer.end()) {
	// 	return std::get<unsigned short>(this->_canBuffer[25]) > 1000.0f;
	// } else {
	// 	return false;
	// }
	return true;
}

void CanBus::open() {
	std::lock_guard<std::mutex> safe_lock(_lock);
  if (_closed) _closed = false;
}

void CanBus::translate(auto& datum, bool signedValue) {
	unsigned char* bytes = reinterpret_cast<unsigned char*>(&datum);
	unsigned char low = bytes[0];
	unsigned char high = bytes[1];
	int num = high * 256 + low;
	if (signedValue) {
		if (num > 32767) {
			num -= 65536;
		}
	}
	datum = (decltype(datum))num;
}

void CanBus::poll() {
	struct can_frame canFrame;
	while (1) {
		struct timeval timeout = {1, 0};
		fd_set readSet;
		FD_ZERO(&readSet);
		FD_SET(this->_canSocket, &readSet);
		if (select((this->_canSocket + 1), &readSet, NULL, NULL, &timeout) >= 0) {
			std::lock_guard<std::mutex> safe_lock(this->_lock);
			if (_closed) {
				this->_canBuffer.clear();
				return;
			}
			if (!read(this->_canSocket, &canFrame, sizeof(struct can_frame))) continue;
			unsigned char *bytes = canFrame.data;
			unsigned int canId = canFrame.can_id;
			if (this->_sensorCanIdMap.find(canId) != this->_sensorCanIdMap.end()) {
				for (const Sensor& sensor: this->_sensorCanIdMap[canId]) {
					unsigned int offset = sensor.traits["canOffset"];
					std::visit(
						[&](auto v) {
							decltype(v) datum = *(reinterpret_cast<decltype(v)*>(bytes + offset));
							if (this->_translationIds.find(sensor.traits["smallId"]) != this->_translationIds.end()) {
								this->translate(datum, sensor.traits["type"] == 'h');
							}
							std::cout << sensor.traits["name"] << ": " << datum << std::endl;
							this->_canBuffer[sensor.traits["smallId"]] = datum;
						},
						sensor.getVariant()
					);
				}
			}
		}
	}
}

void CanBus::decimateFrequency(ReadCallback callback) {
	unsigned volatile timestamp = 0;
	std::unordered_set<unsigned char> changeSet;

	while (1) {
		// Narrow the lock scope
		{
			std::lock_guard<std::mutex> safe_lock(this->_lock);
			if (_closed) {
				_readBuffer.clear();
				return;
			}

			// Determine which sensors we need to read from
			for (auto it = this->_sensorSmallIdMap.begin(); it != this->_sensorSmallIdMap.end(); it++) {
				int divisor = roundf(1000.0f / float(it->second.traits["frequency"]));
				if (timestamp % divisor == 0) {
					changeSet.insert((unsigned char)(it->second.traits["smallId"]));
				}
			}

			// Perform a read on the changeSet if the timestamp aligns with the highest frequency
			int minDivisor = roundf(1000.0f / this->_frequency);
			if (timestamp % minDivisor == 0) {
				// Insert the data into a list if it is statistically significant
				std::vector<SensorVariantPair> data;
				for (const unsigned char sensorSmallId: changeSet) {
					if (this->_readBuffer.find(sensorSmallId) != this->_readBuffer.end()) {
						double lowerBound = this->_sensorSmallIdMap[sensorSmallId].traits["lowerBound"];
						double upperBound = this->_sensorSmallIdMap[sensorSmallId].traits["upperBound"];
						double range = abs(upperBound - lowerBound);
						std::visit(
							[&](auto previousValue) {
								std::visit(
									[&](auto currentValue) {
										double difference = double(abs((double)(currentValue - previousValue)));
										if(range == 0.0) {
											range = 0.1;
										}
										double delta = difference / range;
										if (delta >= SIGNIFICANCE_THRESHOLD) {
											data.push_back({sensorSmallId, currentValue});
										}
									},
									_readBuffer[sensorSmallId]
								);
							},
							_canBuffer[sensorSmallId]
						);
					} else {
						data.push_back({sensorSmallId, _canBuffer[sensorSmallId]});
					}
					this->_readBuffer[sensorSmallId] = _canBuffer[sensorSmallId];
				}
	
				// Execute the callback if there is new data
				if (data.size() != 0) {
					std::future<void> f = std::async(std::launch::async, [=]() {
						callback(timestamp, data);
					});
					changeSet.clear();
				}
			}

			// Increment the timestamp
			timestamp += 1;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void CanBus::close() {
	if (!_closed) {
    {
      std::lock_guard<std::mutex> safe_lock(_lock);
      _closed = true;
    }
  }
}

