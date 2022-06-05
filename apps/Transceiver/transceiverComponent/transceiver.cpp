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