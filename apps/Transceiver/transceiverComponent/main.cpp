#include <stdio.h>
#include "legato.h"
#include <le_thread.h>
#include "interfaces.h"
#include <thread>
#include <mutex>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/can.h>
#include <net/if.h>

#include "can.hpp"
#include "reader.hpp"
#include "server.hpp"
#include "flash.hpp"
#include "sender.hpp"
#include "global.hpp"

#define DEBUG_OFF       1
#define MAX_BUFF_SIZE   65536

// #define SERVER_PORT     8000
// #define SERVER_IP       "18.217.215.72" 
#define SERVER_PORT     8080
#define SERVER_IP       "199.116.235.51"
std::mutex CAN_MUTEX;

#if DEBUG_OFF
#endif

void threadFunction()
{
    LE_INFO("Thread Started\n");
}


COMPONENT_INIT
{
	//Set up environment
    LE_INFO("Starting CAN\n");
	char line[256];
	FILE* fp = popen("/home/root/start_can.sh red 2>&1", "r");  //2>&1 redirect stderr to stdout//
	LE_ASSERT(fp != NULL);
	while (fgets(line, sizeof(line), fp) != NULL){
	    LE_INFO("your.sh output: %s", line);
	}
	int result = pclose(fp);
	LE_FATAL_IF(!WIFEXITED(result), "Could not run your.sh");
	const int exitCode = WEXITSTATUS(result);
	LE_FATAL_IF(exitCode != 0, "your.sh failed with exit code %d", exitCode);
	int soc = openPort("can0");

    //start threads
    std::thread receiverThread (getSensors);
    std::thread senderThread (sendData);
    std::thread writerThread (writeData);

	system("/legato/systems/current/bin/cm data connect");


    //setup socket
    ServerElements se;
    startUDPConnection(&se, (char *)SERVER_IP, SERVER_PORT);

    //sync threads
    receiverThread.join();
    senderThread.join();
    writerThread.join();
    closePort(soc);
}