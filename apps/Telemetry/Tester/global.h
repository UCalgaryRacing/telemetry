#ifndef GLOBAL_H
#define GLOBAL_H

#include <mutex>

typedef struct EncodedData {
    unsigned char *data;
    unsigned int size;
} EncodedData;

static EncodedData GlobalData;
std::mutex mtx;

#endif