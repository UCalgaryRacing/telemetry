#ifndef TRANSMITTERCPPLINK_H
#define TRANSMITTERCPPLINK_H

/*
#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif
*/

#include "encoder.h"
#include "transceiver.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sys/socket.h>


class Transmitter {
    public:
        std::string _serial_number;
        //#TODO inclue httplib.h later
        //httplib::Client _client;
        unsigned short _client_tcp_port = -1;

        int _sockfd;
        unsigned short _remote_udp_port = -1;
        std::string _remote_udp_address;
        //#TODO not sure why this is breaking
        struct sockaddr_in _server_address;

        bool request_session();
        void start_session();
        void stop_session();
        void send_encoded_data(EncodedData data);
};

//wrapper functions
extern "C" bool C_request_session(Transmitter *ptr) {
    return ptr->request_session();
}

extern "C" void C_start_session(Transmitter *ptr) {
    return ptr->start_session();
}

extern "C" void C_stop_session(Transmitter *ptr) {
    return ptr->stop_session();
}

extern "C" void C_send_encoded_data(Transmitter *ptr, EncodedData data) {
    return ptr->send_encoded_data(data);
}

#undef EXTERNC
#endif