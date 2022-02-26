#ifndef SENDING_WORKER_H
#define SENDING_WORKER_H

#define PORT 8000
#define SERVER_ADDRESS "10.12.177.44" // Send data the python server's public IP

void createConnection();
void sendingThread();

#endif
