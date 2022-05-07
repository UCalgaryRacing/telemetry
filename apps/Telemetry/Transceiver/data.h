#include <string>

typedef struct DataVariables {
    std::string _serial_number;
    //#TODO inclue httplib.h later
    //httplib::Client _client;
    unsigned short _client_tcp_port = -1;

    int _sockfd;
    unsigned short _remote_udp_port = -1;
    std::string _remote_udp_address;
    //#TODO not sure why this is breaking
    //struct sockaddr_in _server_address;
} DataVariables;