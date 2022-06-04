#ifndef GLOBAL_H
#define GLOBAL_H

#include <mutex>
#include <string>

// #if 0
// typedef struct EncodedData {
//     unsigned char *data;
//     unsigned int size;
// } EncodedData;

// static EncodedData GlobalData;
// std::mutex mtx;
// #endif

// int SERVER_PORT = 8080;
// char *SERVER_IP = "199.116.235.51";

typedef struct TransceiverData
{
    std::string _api_key;

    std::string _serial_number;
    std::string _web_address = "http://localhost:8080";
    unsigned short _client_tcp_port = -1;
} transceiverData;

#endif