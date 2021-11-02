/*
 * AUTO-GENERATED _componentMain.c for the muxCtrl component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _muxCtrl_mangoh_gpioPinUart1Enable_ServiceInstanceName;
const char** mangoh_gpioPinUart1Enable_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinUart1Enable_ServiceInstanceName;
void mangoh_gpioPinUart1Enable_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinUart1Select_ServiceInstanceName;
const char** mangoh_gpioPinUart1Select_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinUart1Select_ServiceInstanceName;
void mangoh_gpioPinUart1Select_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinSpiEnable_ServiceInstanceName;
const char** mangoh_gpioPinSpiEnable_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinSpiEnable_ServiceInstanceName;
void mangoh_gpioPinSpiEnable_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinSpiSelect_ServiceInstanceName;
const char** mangoh_gpioPinSpiSelect_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinSpiSelect_ServiceInstanceName;
void mangoh_gpioPinSpiSelect_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinUart2Enable_ServiceInstanceName;
const char** mangoh_gpioPinUart2Enable_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinUart2Enable_ServiceInstanceName;
void mangoh_gpioPinUart2Enable_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinUart2Select_ServiceInstanceName;
const char** mangoh_gpioPinUart2Select_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinUart2Select_ServiceInstanceName;
void mangoh_gpioPinUart2Select_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinPcmEnable_ServiceInstanceName;
const char** mangoh_gpioPinPcmEnable_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinPcmEnable_ServiceInstanceName;
void mangoh_gpioPinPcmEnable_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinPcmSelect_ServiceInstanceName;
const char** mangoh_gpioPinPcmSelect_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinPcmSelect_ServiceInstanceName;
void mangoh_gpioPinPcmSelect_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinSdioSelect_ServiceInstanceName;
const char** mangoh_gpioPinSdioSelect_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinSdioSelect_ServiceInstanceName;
void mangoh_gpioPinSdioSelect_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinPcmAnalogSelect_ServiceInstanceName;
const char** mangoh_gpioPinPcmAnalogSelect_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinPcmAnalogSelect_ServiceInstanceName;
void mangoh_gpioPinPcmAnalogSelect_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinIot0Reset_ServiceInstanceName;
const char** mangoh_gpioPinIot0Reset_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinIot0Reset_ServiceInstanceName;
void mangoh_gpioPinIot0Reset_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinIot1Reset_ServiceInstanceName;
const char** mangoh_gpioPinIot1Reset_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinIot1Reset_ServiceInstanceName;
void mangoh_gpioPinIot1Reset_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinIot2Reset_ServiceInstanceName;
const char** mangoh_gpioPinIot2Reset_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinIot2Reset_ServiceInstanceName;
void mangoh_gpioPinIot2Reset_ConnectService(void);
extern const char* _muxCtrl_mangoh_gpioPinArduinoReset_ServiceInstanceName;
const char** mangoh_gpioPinArduinoReset_ServiceInstanceNamePtr = &_muxCtrl_mangoh_gpioPinArduinoReset_ServiceInstanceName;
void mangoh_gpioPinArduinoReset_ConnectService(void);
extern const char* _muxCtrl_mangoh_muxCtrl_ServiceInstanceName;
const char** mangoh_muxCtrl_ServiceInstanceNamePtr = &_muxCtrl_mangoh_muxCtrl_ServiceInstanceName;
void mangoh_muxCtrl_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t muxCtrl_LogSession;
le_log_Level_t* muxCtrl_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _muxCtrl_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _muxCtrl_Init(void)
{
    LE_DEBUG("Initializing muxCtrl component library.");

    // Advertise server-side IPC interfaces.
    mangoh_muxCtrl_AdvertiseService();

    // Connect client-side IPC interfaces.
    mangoh_gpioPinUart1Enable_ConnectService();
    mangoh_gpioPinUart1Select_ConnectService();
    mangoh_gpioPinSpiEnable_ConnectService();
    mangoh_gpioPinSpiSelect_ConnectService();
    mangoh_gpioPinUart2Enable_ConnectService();
    mangoh_gpioPinUart2Select_ConnectService();
    mangoh_gpioPinPcmEnable_ConnectService();
    mangoh_gpioPinPcmSelect_ConnectService();
    mangoh_gpioPinSdioSelect_ConnectService();
    mangoh_gpioPinPcmAnalogSelect_ConnectService();
    mangoh_gpioPinIot0Reset_ConnectService();
    mangoh_gpioPinIot1Reset_ConnectService();
    mangoh_gpioPinIot2Reset_ConnectService();
    mangoh_gpioPinArduinoReset_ConnectService();

    // Register the component with the Log Daemon.
    muxCtrl_LogSession = log_RegComponent("muxCtrl", &muxCtrl_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_muxCtrl_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
