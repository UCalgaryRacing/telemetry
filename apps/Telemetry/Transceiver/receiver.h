/* 
Copyright Schulich Racing, FSAE
Written by Jonathan Mulyk
*/ 

#ifndef RECEIVER
#define RECEIVER

#include "flash.h"

SensorArray fetch_sensors();

void fetch_sensor_diff(uint64_t last_update);

#endif