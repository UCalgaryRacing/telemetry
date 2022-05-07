#ifndef ENCODER_H
#define ENCODER_H

#include <vector>

extern "C" {
  void encode_data(unsigned int timestamp, std::vector<int> &data);
}

#endif