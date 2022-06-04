#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct ServerElements
{
    int sockfd;
    struct sockaddr_in server;
    socklen_t serverLen;
} serverElements;

void startUDPConnection(ServerElements *se, char *IP, int port);

#endif