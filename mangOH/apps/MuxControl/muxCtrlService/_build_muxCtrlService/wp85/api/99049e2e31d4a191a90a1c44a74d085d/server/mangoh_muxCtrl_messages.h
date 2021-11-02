/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MANGOH_MUXCTRL_MESSAGES_H_INCLUDE_GUARD
#define MANGOH_MUXCTRL_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "c2a7af47e98df65903e8e0d5c8896880"

#ifdef MK_TOOLS_BUILD
    extern const char** mangoh_muxCtrl_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*mangoh_muxCtrl_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "mangoh_muxCtrl"
#endif


#define _MAX_MSG_SIZE 12

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_mangoh_muxCtrl_IotAllUart1Off 0
#define _MSGID_mangoh_muxCtrl_Iot0Uart1On 1
#define _MSGID_mangoh_muxCtrl_Iot1Uart1On 2
#define _MSGID_mangoh_muxCtrl_IotAllSpiOff 3
#define _MSGID_mangoh_muxCtrl_Iot0Spi1On 4
#define _MSGID_mangoh_muxCtrl_Iot1Spi1On 5
#define _MSGID_mangoh_muxCtrl_IotAllUart2Off 6
#define _MSGID_mangoh_muxCtrl_Iot2Uart2On 7
#define _MSGID_mangoh_muxCtrl_Uart2DebugOn 8
#define _MSGID_mangoh_muxCtrl_SdioSelMicroSd 9
#define _MSGID_mangoh_muxCtrl_SdioSelIot0 10
#define _MSGID_mangoh_muxCtrl_AudioDisable 11
#define _MSGID_mangoh_muxCtrl_AudioSelectIot0Codec 12
#define _MSGID_mangoh_muxCtrl_AudioSelectOnboardCodec 13
#define _MSGID_mangoh_muxCtrl_AudioSelectInternalCodec 14
#define _MSGID_mangoh_muxCtrl_IotSlot0DeassertReset 15
#define _MSGID_mangoh_muxCtrl_IotSlot1DeassertReset 16
#define _MSGID_mangoh_muxCtrl_IotSlot2DeassertReset 17
#define _MSGID_mangoh_muxCtrl_ArduinoAssertReset 18
#define _MSGID_mangoh_muxCtrl_ArduinoDeassertReset 19
#define _MSGID_mangoh_muxCtrl_ArduinoReset 20


// Define type-safe pack/unpack functions for all enums, including included types

// Define pack/unpack functions for all structures, including included types


#endif // MANGOH_MUXCTRL_MESSAGES_H_INCLUDE_GUARD