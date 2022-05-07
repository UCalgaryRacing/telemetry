#pragma once

typedef struct Sensor {

} Sensor;

typedef struct SensorArray {
    Sensor **sensor_array;
    size_t size;
} SensorArray;

SensorArray read_sensors() {

void write_sensors(SensorArray);

char *create_sensor_row();