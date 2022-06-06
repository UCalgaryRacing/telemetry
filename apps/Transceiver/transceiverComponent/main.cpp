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

#include <iostream>
#include <string>
#include <chrono>

#include "transceiver.hpp"
#include "can.hpp"
#include "reader.hpp"
#include "server.hpp"
#include "flash.hpp"
#include "sender.hpp"
#include "global.hpp"
#include "vfdcp_encoder.hpp"

#define DEBUG_OFF       1
#define MAX_BUFF_SIZE   65536

// #define SERVER_PORT     8000
// #define SERVER_IP       "18.217.215.72" 
// #define SERVER_PORT     8080
// #define SERVER_IP       "199.116.235.51"
std::string serial_number = "7b64abb4-bfe2-4474-8a91-e746a28f8f8e";
std::string api_key = "6ae7867a-b5d3-4b5d-bc68-1b4a53c14296";
//std::mutex CAN_MUTEX;


COMPONENT_INIT
{
    #if 0
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

    std::unique_ptr<Transceiver> transceiver = std::make_unique<Transceiver>(serial_number, api_key);
    // Transceiver transceiver(serial_number, api_key);
    std::vector<Sensor> sensors = transceiver->fetchSensors(); // TODO: Check if vector empty, if so, don't continue
    // Pass back a pointer, if null, there was an error getting sensors, if empty, there are no sensors
    // If null, retry -> do it at a timer
    bool didSessionRequestPass = transceiver->request_session();
    // Check if it passed, if not, try again
    transceiver->initialize_udp();


    auto callback = [&](unsigned int timestamp, std::vector<SensorVariantPair> data) 
    {
        std::vector<unsigned char> bytes = VFDCPEncoder::get().encode_data(timestamp, data);
        for (const unsigned char x: bytes) {
            std::cout << x;
        }
        std::cout << std::endl;
        transceiver->send_vfdcp_data(bytes);
    };
    // Pass this callback into the read can function
    // Get the read can function to simulate can data

    unsigned int timestamp = 0;
    for (int i = 0; i < 1000; i++) {
        std::vector<SensorVariantPair> data{};
        for (const auto& sensor: sensors) {
            SensorDataVariant variant = sensor.get_variant();
            unsigned char id = sensor.traits["smallId"];
            data.push_back(std::make_pair(id, variant));
        }
        callback(timestamp, data);
        timestamp += 33;
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }

    transceiver->stop_session();
    
    // for(const auto & sensor : sensors)
    // {
    //     std::string sensorTraits = sensor.traits.dump();
    //     std::cout << sensorTraits[2] << std::endl;
    //     // sensor.get_variant();
    //     // std::cout << sensor.traits[2] << std::endl;
    // }

    std::cout << "request_session returned: " << didSessionRequestPass << std::endl;

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
    #if 0
    closePort(soc);
    #endif
}