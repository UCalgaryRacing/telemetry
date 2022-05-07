/*
Copyright Schulich Racing, FSAE
Original File Written by Justin Tijunelis
*/

#include "transmitterCPPLink.hpp"
#include <cstring>
#include <vector>
#include <unordered_map>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "data.h"
#include "unistd.h"

bool Transmitter::request_session() {
  // TODO: Create a TCP socket and send the opened port to the server
  // so it knows where to send data. 
  std::string endpoint = "/iot/" + _serial_number + "/start";
  auto res = _client.Get(std::move(endpoint.c_str()));
  if (auto res = _client.Get(std::move(endpoint.c_str()))) {
    json response = json::parse(res->body);
    _remote_udp_port = response["port"];
    _remote_udp_address = response["address"];
    return true;
  } else {
    // TODO: There was an error
    return false;
  }
  return true;
};

void Transmitter::start_session() {
  #if TESTING == 0
    int sockfd;
    struct sockaddr_in server_address;
    if ((_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
      // Failed to create... uhhh...
    }
    memset(&server_address, 0, sizeof(server_address));
    _server_address.sin_family = AF_INET;
    _server_address.sin_port = htons(_remote_udp_port);
    _server_address.sin_addr.s_addr = inet_addr(_remote_udp_address.c_str());
  #endif
}

void Transmitter::stop_session() {
  #if TESTING == 0
  _client.set_keep_alive(false);
  close(_sockfd);
  #endif
}