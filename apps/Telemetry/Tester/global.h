#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct EncodedData {
    unsigned char *data;
    unsigned int size;
} EncodedData;

static EncodedData data;

#endif