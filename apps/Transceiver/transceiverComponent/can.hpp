#ifndef CAN_H
#define CAN_H

#include "global.hpp"
#include "sensor.hpp"
#include <optional>
#include <vector>

void readCAN();
void runReadCAN();
int openPort(const char *port);
int closePort(int soc);

#endif