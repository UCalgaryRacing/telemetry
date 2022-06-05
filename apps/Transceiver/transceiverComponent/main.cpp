#define LEGATO_ON 0
#if lEGATO_ON 
#include <stdio.h>
#include "legato.h"
#include <le_thread.h>
#include "interfaces.h"
#endif
#include <thread>
#include <mutex>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/can.h>
#include <net/if.h>

#include <iostream>
#include <string>

#include "transceiver.hpp"
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
// #define SERVER_PORT     8080
// #define SERVER_IP       "199.116.235.51"
std::string serial_number = "7b64abb4-bfe2-4474-8a91-e746a28f8f8e";
std::string api_key = "6ae7867a-b5d3-4b5d-bc68-1b4a53c14296";
//std::mutex CAN_MUTEX;


#if LEGATO_ON 
COMPONENT_INIT
#else 
int main()
#endif
{
    #if LEGATO_ON
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
    #endif

    printf("Running main.cpp\n");

    // std::unique_ptr<Transceiver> T1 = std::make_unique<Transceiver>(serial_number, api_key);
    Transceiver T1(serial_number, api_key);
    std::vector<Sensor> sensors = T1.fetchSensors();

    for(const auto & sensor : sensors)
    {
        std::cout << sensor.traits << std::endl;
    }

    //start threads
    std::thread receiverThread(getSensors);
    // std::thread senderThread (sendData);
    // std::thread writerThread (writeData);

    #if LEGATO_ON
	system("/legato/systems/current/bin/cm data connect");
    #endif


    //setup socket
    // ServerElements se;
    // startUDPConnection(&se, (char *)SERVER_IP, SERVER_PORT);

    //sync threads
    receiverThread.join();
    // senderThread.join();
    // writerThread.join();
    #if LEGATO_ON
    closePort(soc);
    #endif
}