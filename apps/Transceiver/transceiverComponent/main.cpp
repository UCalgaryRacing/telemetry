// Copyright Schulich Racing, FSAE
// Written by Jon Mulyk and Justin Tijunelis

#include "legato.h"
#include <thread>
#include <optional>
#include <vector>
#include "can.hpp"
#include "constants.h"
#include "transceiver.hpp"
#include "vfdcp_encoder.hpp"

COMPONENT_INIT {
	// Connect to LTE
    system("sh /home/root/start_connect.sh");

    // Attempt to fetch the sensors from the server
    Transceiver transceiver = Transceiver(SERIAL_NUMBER, API_KEY, WEB_SERVER_ENDPOINT);
    std::optional<std::vector<Sensor>> sensors = std::nullopt; 
    while (!sensors.has_value()) {
        sensors = transceiver.fetchSensors();
    }

    // If there are no sensors, there is no point in continuing
    if (sensors.value().size() == 0) {
        return;
    }

    // Attempt to start a session with the server
    while (!transceiver.requestSession());
    transceiver.initializeUdp();

    // Attempt to start the CAN bus
    auto callback = [&](unsigned int timestamp, std::vector<SensorVariantPair> data) {
        std::vector<unsigned char> bytes = encode_data(timestamp, data);
        transceiver.sendVfdcpData(bytes);
    };
    CanBus canBus = CanBus(sensors.value(), callback);
    while (!canBus.initializeCanBus());

    // Start the CAN reading thread
    std::thread canReadingThread([&]{ canBus.readCanBus(); });
    canReadingThread.join();
}