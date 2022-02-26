//change to #ifndef
#pragma once

typedef struct EncodedData {
    unsigned char *data;
    unsigned int size;
} EncodedData;

EncodedData encode_data(unsigned int, unsigned int);
