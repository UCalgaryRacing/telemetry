// Copyright Schulich Racing FSAE
// Written by Justin Tijunelis and Jon Mulyk

#include "transceiver.hpp"

Transceiver::~Transceiver() {}

std::optional<std::vector<Sensor>> Transceiver::fetchSensors() {
    std::vector<Sensor> sensors;
    std::string endpoint = "/api/database/sensors/thing/" + _serialNumber;
    httplib::Client client(this->_webAddress);
    client.set_read_timeout(100000);
    httplib::Headers headers = {{"apiKey", _apiKey}};
    if (auto res = client.Get(std::move(endpoint.c_str()), headers)) {
        if (res->status == 200) {
            json body = json::parse(res->body).at("data");
            for (json::iterator it = body.begin(); it != body.end(); ++it) {
                sensors.push_back(Sensor(*it));
            }
        } else {
            return std::nullopt;
        }
    } else {
        return std::nullopt;
    }
    return std::optional<std::vector<Sensor>>{sensors};
}

SensorDiff Transceiver::fetch_sensor_diff(unsigned long long last_update) {
  std::unordered_map<unsigned char, Sensor> sensor_map;
  std::vector<std::string> ids;
  std::string endpoint = "/api/database/sensors/thing/" + _serialNumber + "/lastUpdate/" + std::to_string(last_update);
  httplib::Client client(this->_webAddress);
  client.set_read_timeout(100000);
  httplib::Headers headers = {{"apiKey", _apiKey}};
  if (auto res = client.Get(std::move(endpoint.c_str()), headers)) {
    if (res->status == 200) {
      // Parse the updated sensors
      json body = json::parse(res->body).at("data").at("sensors");
      for (json::iterator it = body.begin(); it != body.end(); ++it) {
        json element = *it; // What if this fails?
        unsigned char small_id = element.at("smallId");
        sensor_map[small_id] = Sensor(*it);
      }

      // Get all the sensor ids to consolidate against deleted sensors
      ids = (std::vector<std::string>)json::parse(res->body).at("data").at("existingSensorIds");
    } else {
      return std::nullopt;
    }
  } else {
    return std::nullopt;
  }
  return std::make_pair(sensor_map, ids);
}

std::unordered_map<int, json> Transceiver::populateSensors()
{
    std::unordered_map<int, json> sensorMap;
    FILE *file;
    if((file = fopen(_sensorDataFile.c_str(), "r")) == NULL)
    {
        //file doesn't exist
        printf("ERROR IN READING FILE\n");
        exit(1);
    }

    int id;
    char* sensorJson;

    //scan each line for <int> <string>
    while(fscanf(file, "%d %s", &id, sensorJson) != EOF)
    {
        //sensorMap[id] = json::parse(std::string((sensorJson)));
        sensorMap[id] = json::parse((sensorJson));
    }

    fclose(file);

    return sensorMap;
}

void Transceiver::cacheSensors(std::vector<Sensor> sensors)
{
    std::unordered_map<int, json> sensorMap = populateSensors;

    FILE *file;
    if((file = fopen(_sensorDataFile.c_str(), "w")) == NULL)
    {
        //error
    }

    //write all sensors from incoming list
    for(auto const & sensor : sensors)
    {
        int sensorId = (int)sensor.traits["smallId"];
        //if not in sensorMap (aka new)
        //add all sensors that have been recently pulled
        fprintf(file, "%d %s\n", sensorId, sensor.traits.dump().c_str());
    }

    //write all sensors that have been cached and not updated
    for(auto const & sensor : sensorMap)
    {
        int sensorId = (int)sensor.traits["smallId"];
        if(sensorMap.find(sensorId) == sensorMap.end())
        {
            fprintf(file, "%d %s\n", sensorId, std::string(sensorMap[sensorId]));
        }
    }

    fclose(file);
}

bool Transceiver::requestSession() {
    std::string endpoint = "/api/iot/" + _serialNumber + "/start";
    httplib::Client client(this->_webAddress);
    httplib::Headers headers = {{"apiKey", _apiKey}};
    if (auto res = client.Get(std::move(endpoint.c_str()), headers)) {
        if (res->status == 200) {
            json response = json::parse(res->body);
            this->_remoteUdpPort = response.at("port");
            this->_remoteUdpAddress = response.at("address");
            return true;
        }
    }
    return false;
}

bool Transceiver::initializeUdp() {
    if ((this->_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) return false;
    memset(&this->_serverAddress, 0, sizeof(this->_serverAddress));
    this->_serverAddress.sin_family = AF_INET;
    this->_serverAddress.sin_port = htons(this->_remoteUdpPort);
    this->_serverAddress.sin_addr.s_addr = inet_addr(this->_remoteUdpAddress.c_str());
    return true;
}

void Transceiver::stopSession() {
    close(_sockfd);
}

void Transceiver::sendVfdcpData(std::vector<unsigned char> &bytes) {
    // Put the data into a byte array
    unsigned char buffer[bytes.size()];
    for (unsigned int i = 0; i < bytes.size(); i++)
        buffer[i] = bytes[i];

    // Send the data
    int result = sendto(
        this->_sockfd,
        (const unsigned char *)buffer,
        bytes.size(),
        0,
        (const struct sockaddr *)&this->_serverAddress,
        sizeof(this->_serverAddress)
    );
    perror("here");
    std::cout << result << std::endl;
}