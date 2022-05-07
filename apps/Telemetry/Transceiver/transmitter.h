/* 
Copyright Schulich Racing, FSAE
Written by Jonathan Mulyk
*/ 

#ifndef TRANSMITTER_H 
#define TRNASMITTER_H

#include "encoder.h"

#if 0//[]
#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif
#endif

bool request_session();

void start_session();

void stop_session();

void send_encoded_data(EncodedData data);

#endif