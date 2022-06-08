#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

#include <vector>
#include <string> 
#include <arpa/inet.h>
#include <unistd.h>
#include "../External Libraries/httplib.h"
#include "../External Libraries/json.hpp"
#include "sensor.hpp"

class Transceiver {
  private:
    // REST request fields
    std::string _serialNumber;
    std::string _webAddress;
    std::string _apiKey;

    // UDP socket fields
    int _sockfd;
    unsigned short _remoteUdpPort = -1;
    std::string _remoteUdpAddress;
    struct sockaddr_in _serverAddress;

  public:
    Transceiver() = delete;
    Transceiver(std::string sn, std::string key, std::string address) : _serialNumber(sn), _apiKey(key), _webAddress(address) {}
    ~Transceiver();

    /**
     * @brief Fetch the entire list of sensors for the particular serial number of a "thing."
     */
    std::vector<Sensor> fetchSensors();

     /**
     * @brief Requests the server to start a session, gets a UDP port to send to if successful. 
     * Returns true on success and false on failure. 
     */
    bool requestSession();

    /**
     * @brief Opens the UDP socket through which compressed data is sent. 
     */
    bool initializeUDP();

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