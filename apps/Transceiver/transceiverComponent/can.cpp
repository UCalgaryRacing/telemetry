#define LEGATO_ON 0
#if LEGATO_ON
#include "legato.h"
#include <le_thread.h>
#include "interfaces.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/can.h>
#include <net/if.h>
#include <chrono>
#include "../External Libraries/httplib.h"
#include "../External Libraries/json.hpp"
#include "sensor.hpp"
#include "can.hpp"

#define SIGNIFICANCE_THRESHOLD 0.00005f // 0.005% change is significant

CanBus::CanBus(std::vector<Sensor>& sensors, ReadCallback callback) {
	// Get the callback frequency, create the sensor map, and initialize the buffer
	unsigned int highestFrequency = 0;
	for (const Sensor& sensor: sensors) {
		if (sensor.traits["frequency"] > highestFrequency) {
			highestFrequency = sensor.traits["frequency"];
		}
		this->_sensorMap[sensor["smallId"]] = sensor;
		this->_canBuffer[sensor["smallId"]] = sensor.get_variant();
	}
	this->_frequency = highestFrequency;
	this->_callback = callback;
}

// https://github.com/mangOH/mangOH/blob/master/linux_kernel_modules/can_common/start_can.sh
bool CanBus::initializeCanBus() {
	// Attempt to open the start can shell file
	char line[256];
	FILE* fp = popen("/home/root/start_can.sh red 2>&1", "r");  //2>&1 redirect stderr to stdout//
	if (fp == NULL) return false;

	// Attempt to close the shell file
	int result = pclose(fp);
	if (!WIFEXITED(result)) return false;
	const int exitCode = WEXITSTATUS(result);
	if (exitCode != 0) return false;

	// Attempt to open the CAN socket
	struct ifreq ifr;
	struct socaddr_can addr;
	sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (sock < 0) return false;
	addr.can_family = AF_CAN;
	strcpy(ifr.ifr_name, "can0");
	if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
		return false;
	}
	addr.can_ifindex = ifr.ifr_index;
	fcntl(sock, F_SETFL, O_NONBLOCK);
	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		return false;
	}

	// Set the can socket and return success
	this->_canSocket = sock;
	return true;
}

void CanBus::openCanBus() {
	std::lock_guard<std::mutex> safe_lock(_lock);
  if (_closed) _closed = false;
}

// TODO: Check if can was initialized
void CanBus::pollCanBus() {
	struct can_frame canFrame;
	while (1) {
		struct timeval timeout = {1, 0};
		fd_set readSet;
		FD_ZERO(&readSet);
		FD_SET(this->_canSocket);
		if (select((this->_canSocket + 1), &readSet, NULL, NULL, &timeout) >= 0) {
			std::lock_guard<std::mutex> safe_lock(_lock);
			if (_closed) return;

			if (FD_ISSET(this->_canSocket, &readSet)) {
				int rcvd = read(this->_canSocket, &canFrame, sizeof(struct can_frame));
				if (rcvd) {
					unsigned char bytesLength = canFrame.can_dlc;
					unsigned char *bytes = canFrame.data;
					unsigned int canId = canFrame.can_id;

					// TODO: Determine which sensor this can id is for
					// TODO: Visit the variant of the sensor and put in the bytes data into the can buffer
					// TODO: Add calibration here!
				}
			}
		}
	}
}

// TODO: Don't allow start if CAN was not initialized
void CanBus::readCanBus() {
	unsigned volatile timestamp = 0;
	std::unordered_set<unsigned char> changeSet;

	// TODO: Start the pollCanBus function on a thread

	while (1) {
		// Narrow the lock scope
		{
			std::lock_guard<std::mutex> safe_lock(_lock);
			if (_closed) return; // TODO: Join polling thread

			// Determine which sensors we need to read from
			for (auto it = this->_sensorMap.begin(); it != this->_sensorMap.end(); it++) {
				int divisor = roundf(1000.0f / float(it->second.traits["frequency"]));
				if (timestamp % this->_frequency == 0) {
					changeSet.insert(it->second.traits["smallId"])
				}
			}

			// Perform a read on the changeSet if the timestamp aligns with the highest frequency
			int minDivisor = roundf(1000.0f / this->_frequency);
			if (timestamp % minDivisor === 0) {
				// Insert the data into a list if it is statistically significant
				std::vector<SensorVariantPair> data;
				for (const unsigned char& sensorSmallId: changeSet) {
					if (this->_readBuffer.find(sensorSmallId) != this->_readBuffer.end()) {
						double lowerBound = this->_sensorMap[sensorSmallId].traits["lowerBound"];
						double upperBound = this->_sensorMap[sensorSmallId].traits["upperBound"];
						double range = abs(upperBound - lowerBound);
						std::visit(
							[&](auto previousValue) {
								std::visit(
									[&](auto currentValue) {
										double difference = double(abs(currentValue - previousValue));
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
						this->_callback(timestamp, data);
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

void CanBus::closeCanBus() {
	if (!_closed) {
    {
      std::lock_guard<std::mutex> safe_lock(_lock);
      _closed = true;
    }
  }
}

