/* 
Copyright Schulich Racing, FSAE
Written by Jonathan Mulyk
*/ 

#ifndef ENCODER_H
#define ENCODER_H

typedef struct EncodedData {
    unsigned char *data;
    unsigned int size;
} EncodedData;

EncodedData encode_data(unsigned int, unsigned int);

#endif