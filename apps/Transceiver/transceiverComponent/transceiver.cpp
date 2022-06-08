#include "transceiver.hpp"

Transceiver::~Transceiver() {}

std::vector<Sensor> Transceiver::fetchSensors() {
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
        }
    }
    return sensors;
}

bool Transceiver::requestSession() {
    std::string endpoint = "/api/iot/" + _serialNumber + "/start";
    httplib::Client client(this->_webAddress);
    httplib::Headers headers = {{"apiKey", _apiKey}};
    if (auto res = client.Get(std::move(endpoint.c_str()), headers)) {
        if (res->status == 200) {
            json response = json::parse(res->body);
            _remoteUdpPort = response.at("port");
            _remoteUdpAddress = response.at("address");
            return true;
        }
    }
    return false;
}

bool Transceiver::initializeUDP() {
    struct sockaddr_in serverAddress;
    if ((_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) return false;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(_remoteUdpPort);
    serverAddress.sin_addr.s_addr = inet_addr(_remoteUdpAddress.c_str());
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
    int sentBytes = sendto(
        _sockfd,
        (const unsigned char *)buffer,
        bytes.size(),
        0,
        (const struct sockaddr *)&_serverAddress,
        sizeof(_serverAddress)
    );
}