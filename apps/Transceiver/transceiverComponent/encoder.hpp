#ifndef ENCODER_H
#define ENCODER_H

#include <vector>

void write_data(unsigned char *data, unsigned int size);
void encode_data(unsigned int timestamp, std::vector<int> &data);

#endif