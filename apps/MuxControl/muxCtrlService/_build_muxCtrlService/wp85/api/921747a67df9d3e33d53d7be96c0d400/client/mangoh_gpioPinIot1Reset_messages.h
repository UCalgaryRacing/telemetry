/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MANGOH_GPIOPINIOT1RESET_MESSAGES_H_INCLUDE_GUARD
#define MANGOH_GPIOPINIOT1RESET_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "eb4b6dc575d64f27484e7657275f11fd"

#ifdef MK_TOOLS_BUILD
    extern const char** mangoh_gpioPinIot1Reset_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*mangoh_gpioPinIot1Reset_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "le_gpio"
#endif


#define _MAX_MSG_SIZE 24

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_mangoh_gpioPinIot1Reset_SetInput 0
#define _MSGID_mangoh_gpioPinIot1Reset_SetPushPullOutput 1
#define _MSGID_mangoh_gpioPinIot1Reset_SetTriStateOutput 2
#define _MSGID_mangoh_gpioPinIot1Reset_SetOpenDrainOutput 3
#define _MSGID_mangoh_gpioPinIot1Reset_EnablePullUp 4
#define _MSGID_mangoh_gpioPinIot1Reset_EnablePullDown 5
#define _MSGID_mangoh_gpioPinIot1Reset_DisableResistors 6
#define _MSGID_mangoh_gpioPinIot1Reset_Activate 7
#define _MSGID_mangoh_gpioPinIot1Reset_Deactivate 8
#define _MSGID_mangoh_gpioPinIot1Reset_SetHighZ 9
#define _MSGID_mangoh_gpioPinIot1Reset_Read 10
#define _MSGID_mangoh_gpioPinIot1Reset_AddChangeEventHandler 11
#define _MSGID_mangoh_gpioPinIot1Reset_RemoveChangeEventHandler 12
#define _MSGID_mangoh_gpioPinIot1Reset_SetEdgeSense 13
#define _MSGID_mangoh_gpioPinIot1Reset_DisableEdgeSense 14
#define _MSGID_mangoh_gpioPinIot1Reset_IsOutput 15
#define _MSGID_mangoh_gpioPinIot1Reset_IsInput 16
#define _MSGID_mangoh_gpioPinIot1Reset_GetEdgeSense 17
#define _MSGID_mangoh_gpioPinIot1Reset_GetPolarity 18
#define _MSGID_mangoh_gpioPinIot1Reset_IsActive 19
#define _MSGID_mangoh_gpioPinIot1Reset_GetPullUpDown 20


// Define type-safe pack/unpack functions for all enums, including included types

static inline bool mangoh_gpioPinIot1Reset_PackPolarity
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinIot1Reset_Polarity_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool mangoh_gpioPinIot1Reset_UnpackPolarity
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinIot1Reset_Polarity_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool mangoh_gpioPinIot1Reset_PackEdge
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinIot1Reset_Edge_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool mangoh_gpioPinIot1Reset_UnpackEdge
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinIot1Reset_Edge_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

static inline bool mangoh_gpioPinIot1Reset_PackPullUpDown
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinIot1Reset_PullUpDown_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool mangoh_gpioPinIot1Reset_UnpackPullUpDown
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinIot1Reset_PullUpDown_t* valuePtr
)
{
    bool result;
    uint32_t value;
    result = le_pack_UnpackUint32(bufferPtr, sizePtr, &value);
    if (result)
    {
        *valuePtr = value;
    }
    return result;
}

// Define pack/unpack functions for all structures, including included types


#endif // MANGOH_GPIOPINIOT1RESET_MESSAGES_H_INCLUDE_GUARD