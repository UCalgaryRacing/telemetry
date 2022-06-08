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
#include "vfdcp_encoder.hpp"

#define DEBUG_OFF       1
#define MAX_BUFF_SIZE   65536

std::string webAddress = "http://199.116.235.51:8080";
std::string serialNumber = "7b64abb4-bfe2-4474-8a91-e746a28f8f8e";
std::string apiKey = "6ae7867a-b5d3-4b5d-bc68-1b4a53c14296";

COMPONENT_INIT {
    // Connect the hardware to LTE - TODO: Check if this works!!
    system("/legato/systems/current/bin/cm data connect");

    // Attempt to fetch the sensors from the server
    Transceiver transceiver = Transceiver(serialNumber, apiKey, webAddress);
    std::vector<Sensor> sensors = transceiver->fetchSensors(); // TODO: Need to return a nullptr if error
    if (sensors.size() == 0) {
        // There are no sensors for this!
        // What do we do? Probably just nothing
    }

    // Attempt to start a session with the server
    while (!transceiver->requestSession()) {
        // Wait until we can start a session!
    }
    transceiver->initializeUdp();

    // Attempt to start the CAN bus
    auto callback = [&](unsigned int timestamp, std::vector<SensorVariantPair> data) {
        std::vector<unsigned char> bytes = encode_data(timestamp, data);
        transceiver->sendVfdcpData(bytes);
    }
    CanBus canBus = CanBus(sensors, callback);
    while (!canBus.initializeCanBus()) {
        // Something is going wrong with initialization!
    }

    // TODO: Start readCanBus on a new thread
}