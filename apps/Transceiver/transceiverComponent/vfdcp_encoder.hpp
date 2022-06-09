// Copyright Schulich Racing, FSAE
// Written by Justin Tijunelis

#ifndef VFDCP_ENCODER_H
#define VFDCP_ENCODER_H

#include "sensor.hpp"
#include <tuple>
#include <vector>
#include <variant>
#include <algorithm>
#include <unordered_map>

/**
 * @brief Encodes data into the format:
 * Sensor Count (1 Byte), Timestamp (4 bytes), Sensors IDs (Variable; Equal to Sensor Count), 
 * Sensor Values (Variable; A function of sensor type and Sensor Count)
 */
std::vector<unsigned char> encode_data(unsigned int timestamp, std::vector<SensorVariantPair>& data);

#endif