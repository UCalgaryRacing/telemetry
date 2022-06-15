// Copyright Schulich Racing FSAE
// Written by Justin Tijunelis and Jon Mulyk

#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

#include <vector>
#include <string> 
#include <arpa/inet.h>
#include <unistd.h>
#include <optional>
#include "../inc/httplib.h"
#include "../inc/json.hpp"
#include "sensor.hpp"

using SensorDiff = std::optional<std::pair<std::unordered_map<unsigned char, Sensor>, std::vector<std::string>>>;

class Transceiver {
  private:
    // REST request fields
    std::string _serialNumber;
    std::string _apiKey;
    std::string _webAddress;

    // UDP socket fields
    int _sockfd;
    unsigned short _remoteUdpPort = -1;
    std::string _remoteUdpAddress;
    struct sockaddr_in _serverAddress;

    std::string _sensorDataFile = "~/sensor_data";

  public:
    Transceiver() = delete;
    Transceiver(std::string sn, std::string key, std::string address) : _serialNumber(sn), _apiKey(key), _webAddress(address) {}
    ~Transceiver();

    /**
     * @brief Fetch the entire list of sensors for the particular serial number of a "thing."
     */
    std::optional<std::vector<Sensor>> fetchSensors();

    /**
     * @brief Fetch the sensors that have changed since the last update 
     */
    SensorDiff fetch_sensor_diff(unsigned long long last_update);

    /**
     * @brief
     */
    std::unordered_map<int, json> populateSensors();

    /**
     * @brief
     */
    void cacheSensors(std::vector<Sensor> sensors);

     /**
     * @brief Requests the server to start a session, gets a UDP port to send to if successful. 
     * Returns true on success and false on failure. 
     */
    bool requestSession();

    /**
     * @brief Opens the UDP socket through which compressed data is sent. 
     */
    bool initializeUdp();

    /**
     * @brief Closes the UDP socket " " " "
     */
    void stopSession();

    /**
     * @brief Sends compressed data to the server via UDP
     */
    void sendVfdcpData(std::vector<unsigned char>& bytes);
};

#endif