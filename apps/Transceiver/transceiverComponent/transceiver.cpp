#include "transceiver.hpp"

Transceiver::~Transceiver() {}

std::vector<Sensor> Transceiver::fetchSensors()
{
    std::vector<Sensor> sensors;
    std::string endpoint = "/api/database/sensors/thing/" + _serial_number;
    httplib::Client client(this->_web_address);
    client.set_read_timeout(100000);
    httplib::Headers headers = {{"apiKey", _api_key}};
    if (auto res = client.Get(std::move(endpoint.c_str()), headers))
    {
        if (res->status == 200)
        {
            json body = json::parse(res->body).at("data");
            for (json::iterator it = body.begin(); it != body.end(); ++it)
            {
                sensors.push_back(Sensor(*it));
            }
        }
    }

    return sensors;
}

bool Transceiver::request_session()
{
    std::string endpoint = "/api/iot/" + _serial_number + "/start";
    httplib::Client client(this->_web_address);
    httplib::Headers headers = {{"apiKey", _api_key}};
    if (auto res = client.Get(std::move(endpoint.c_str()), headers))
    {
        if (res->status == 200)
        {
            json response = json::parse(res->body);
            _remote_udp_port = response.at("port");
            _remote_udp_address = response.at("address");
            // TODO: Create a tcp port in the future to connect to the server
            return true;
        }
    }

        return false;
}

bool Transceiver::initialize_udp()
{
    struct sockaddr_in server_address;
    if ((_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        return false;
    }
    memset(&server_address, 0, sizeof(server_address));
    _server_address.sin_family = AF_INET;
    _server_address.sin_port = htons(_remote_udp_port);
    _server_address.sin_addr.s_addr = inet_addr(_remote_udp_address.c_str());
    // std::string svradr = "srvelocity.com";
    // _server_address.sin_addr.s_addr = inet_addr(svradr.c_str());

    std::cout << "udp port: " << _remote_udp_port << "\nudp address: " << _remote_udp_address << std::endl;

    return true;
}

void Transceiver::stop_session()
{
    close(_sockfd);
    // int status = close(_sockfd);
    // Do something with this status!
}

void Transceiver::send_vfdcp_data(std::vector<unsigned char> &bytes)
{
    unsigned char buffer[bytes.size()];
    for (unsigned int i = 0; i < bytes.size(); i++)
        buffer[i] = bytes[i];
    int sentBytes = sendto(
        _sockfd,
        (const unsigned char *)buffer,
        bytes.size(),
        0, // TODO: Not sure what this should be
        (const struct sockaddr *)&_server_address,
        sizeof(_server_address));

    if (sentBytes <= 0)
    {
        printf("Failed to send data in %s\n", __func__);
    } 

    #if 1
    printf("SENT %d bytes in %s\n", sentBytes, __func__);
    #endif 
}