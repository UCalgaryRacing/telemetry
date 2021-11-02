/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MANGOH_GPIOPINSDIOSELECT_MESSAGES_H_INCLUDE_GUARD
#define MANGOH_GPIOPINSDIOSELECT_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "eb4b6dc575d64f27484e7657275f11fd"

#ifdef MK_TOOLS_BUILD
    extern const char** mangoh_gpioPinSdioSelect_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*mangoh_gpioPinSdioSelect_ServiceInstanceNamePtr)
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

#define _MSGID_mangoh_gpioPinSdioSelect_SetInput 0
#define _MSGID_mangoh_gpioPinSdioSelect_SetPushPullOutput 1
#define _MSGID_mangoh_gpioPinSdioSelect_SetTriStateOutput 2
#define _MSGID_mangoh_gpioPinSdioSelect_SetOpenDrainOutput 3
#define _MSGID_mangoh_gpioPinSdioSelect_EnablePullUp 4
#define _MSGID_mangoh_gpioPinSdioSelect_EnablePullDown 5
#define _MSGID_mangoh_gpioPinSdioSelect_DisableResistors 6
#define _MSGID_mangoh_gpioPinSdioSelect_Activate 7
#define _MSGID_mangoh_gpioPinSdioSelect_Deactivate 8
#define _MSGID_mangoh_gpioPinSdioSelect_SetHighZ 9
#define _MSGID_mangoh_gpioPinSdioSelect_Read 10
#define _MSGID_mangoh_gpioPinSdioSelect_AddChangeEventHandler 11
#define _MSGID_mangoh_gpioPinSdioSelect_RemoveChangeEventHandler 12
#define _MSGID_mangoh_gpioPinSdioSelect_SetEdgeSense 13
#define _MSGID_mangoh_gpioPinSdioSelect_DisableEdgeSense 14
#define _MSGID_mangoh_gpioPinSdioSelect_IsOutput 15
#define _MSGID_mangoh_gpioPinSdioSelect_IsInput 16
#define _MSGID_mangoh_gpioPinSdioSelect_GetEdgeSense 17
#define _MSGID_mangoh_gpioPinSdioSelect_GetPolarity 18
#define _MSGID_mangoh_gpioPinSdioSelect_IsActive 19
#define _MSGID_mangoh_gpioPinSdioSelect_GetPullUpDown 20


// Define type-safe pack/unpack functions for all enums, including included types

static inline bool mangoh_gpioPinSdioSelect_PackPolarity
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinSdioSelect_Polarity_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool mangoh_gpioPinSdioSelect_UnpackPolarity
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinSdioSelect_Polarity_t* valuePtr
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

static inline bool mangoh_gpioPinSdioSelect_PackEdge
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinSdioSelect_Edge_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool mangoh_gpioPinSdioSelect_UnpackEdge
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinSdioSelect_Edge_t* valuePtr
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

static inline bool mangoh_gpioPinSdioSelect_PackPullUpDown
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinSdioSelect_PullUpDown_t value
)
{
    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

static inline bool mangoh_gpioPinSdioSelect_UnpackPullUpDown
(
    uint8_t **bufferPtr,
    size_t* sizePtr,
    mangoh_gpioPinSdioSelect_PullUpDown_t* valuePtr
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


#endif // MANGOH_GPIOPINSDIOSELECT_MESSAGES_H_INCLUDE_GUARD