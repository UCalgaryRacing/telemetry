/* 
Copyright Schulich Racing, FSAE
Written by Jonathan Mulyk
*/ 

#include "transmitter.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#include "transmitterCPPLink.hpp"

#if 0
extern bool request_session();

void C_func(struct Thing *p);

void Call_C_func(struct Thing *p)
{
    C_func(p);
}
#endif

typedef struct ConnectionElements
{
    int sockfd;
    struct sockaddr_in server;
    socklen_t serverLength;
} ConnectinElement;

void C_start_session(struct Trasmitter *ptr)
{
    ConnectionElements ce;
    int sockfd;
    struct sockaddr_in server_address;
    if ((_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
      // Failed to create... uhhh...
    }
    memset(&server_address, 0, sizeof(server_address));
    _server_address.sin_family = AF_INET;
    _server_address.sin_port = htons(_remote_udp_port);
    _server_address.sin_addr.s_addr = inet_addr(_remote_udp_address.c_str());
}

void Call_C_start_session(struct Transmitter *ptr)
{
    C_start_session(ptr);
}

void send_encoded_data(
        EncodedData data, 
        int port, 
        char *serverIP, 
        int sockFd,
        const unsigned char *buffer, 
        int bufferSize
    )
{
    sendto(sockFd, (const unsigned char*)buffer, bufferSize, MSG_CONFIRM,
    (const struct sockaddr *)&_server_address, sizeof(_server_address));
}

#if 0
bool request_session() {
}

void start_session() {

}

void stop_session() {

}

void send_encoded_data(EncodedData data) {

}
#endif