// Copyright Schulich Racing, FSAE
// Written by Jon Mulyk and Justin Tijunelis

#include "legato.h"
#include <thread>
#include <iostream>
#include <optional>
#include <chrono>
#include <vector>
#include "can.hpp"
#include "constants.h"
#include "transceiver.hpp"
#include "vfdcp_encoder.hpp"

COMPONENT_INIT {
	// Connect to LTE and start the CAN driver
    system("sh /home/root/start_connect.sh &");
    while (1) {
        char line[256];
        FILE* fp = popen("/home/root/start_can.sh red 2>&1", "r");
        LE_ASSERT(fp != NULL);
        if (fp == NULL) continue;
        while (fgets(line, sizeof(line), fp) != NULL);
        int result = pclose(fp);
        if (!WIFEXITED(result)) continue;
        if (WEXITSTATUS(result) != 0) continue;
        break;
    }

    // Attempt to fetch the sensors from the server
    Transceiver transceiver = Transceiver(SERIAL_NUMBER, API_KEY, WEB_SERVER_ENDPOINT);
    std::optional<std::vector<Sensor>> sensors = std::nullopt; 
    while (!sensors.has_value()) {
        sensors = transceiver.fetchSensors();
    }

    // If there are no sensors, there is no point in continuing
    if (sensors.value().size() == 0) return;

    // Start polling the CAN bus
    CanBus canBus = CanBus(sensors.value());
    while (!canBus.initialize());
    canBus.open();
	std::thread pollingThread([&]{ canBus.poll(); });

    // Wait for the engine to start before starting telemetry
    while (!canBus.engineStarted());

    // Attempt to start a session with the server
    std::cout << "requesting session" << std::endl;
    while (!transceiver.requestSession());
    transceiver.initializeUdp();

    // Start the CAN reading thread
    auto callback = [&](unsigned int timestamp, std::vector<SensorVariantPair> data) {
        std::vector<unsigned char> bytes = encode_data(timestamp, data);
        transceiver.sendVfdcpData(bytes);
    };
    canBus.decimateFrequency(callback);
    pollingThread.join();
}

// // TESTING
// std::vector<SensorVariantPair> data{};
// for (auto sensor: sensors.value()) {
//     SensorVariantPair datum = std::make_pair(sensor.traits["smallId"], sensor.get_variant());
//     data.push_back(datum);
// }
// transceiver.initializeUdp();
// for (unsigned int i = 0; i < 1000; i++) {
//     std::vector<unsigned char> bytes = encode_data(i, data);
//     transceiver.sendVfdcpData(bytes);
//     std::this_thread::sleep_for(std::chrono::milliseconds(10));
// }

// return;