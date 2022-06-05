#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

#include <vector>
#include <string> 
#include <arpa/inet.h>
#include <unistd.h>
#include "../External Libraries/httplib.h"
#include "../External Libraries/json.hpp"

#include "sensor.hpp"

class Transceiver 
{
  private:

    // REST request fields
    std::string _serial_number;
    //std::string _web_address = "http://localhost:8080";
    std::string _web_address = "http://199.116.235.51:8080";
    unsigned short _client_tcp_port = -1;

    std::string _api_key;

    // UDP socket fields
    int _sockfd;
    unsigned short _remote_udp_port = -1;
    std::string _remote_udp_address;
    struct sockaddr_in _server_address;

    // TODO: TCP socket fields

  public:
    Transceiver(std::string sn, std::string key) : _serial_number(sn), _api_key(key) {}
    ~Transceiver();

    /**
     * @brief Fetch the entire list of sensors for the particular serial number of a "thing."
     */
    std::vector<Sensor> fetchSensors();
};

#endif