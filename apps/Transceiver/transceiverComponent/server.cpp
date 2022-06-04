#include "server.hpp"

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

void startUDPConnection(ServerElements *se, char *IP, int port)
{
    struct sockaddr_in server;
    struct timeval tv;

    //create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd < 0)
    {
        printf("socket function failed\n");
        close(sockfd);
        exit(1);
    }

    //clear the server and define PORT 
    memset((char *) &server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    //server.sin_addr.s_addr = INADDR_ANY;
    
    //IP
    if(inet_pton(AF_INET, IP, &server.sin_addr) == 0)
    {
        printf("inet_pton function failed\n");
        exit(1);
    }

    //set timeout value to be 3 seconds
    tv.tv_sec = 3;
    //set microseconds to be 0
    tv.tv_usec = 0;
    
    //set the sock decriptor to have the timeout
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*) &tv, sizeof(tv));

    //store in structure
    se->sockfd = sockfd;
    se->server = server;
    se->serverLen = sizeof(server);
}