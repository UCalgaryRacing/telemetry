/*
 * AUTO-GENERATED _componentMain.c for the batteryComponentRed component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _batteryComponentRed_le_cfg_ServiceInstanceName;
const char** le_cfg_ServiceInstanceNamePtr = &_batteryComponentRed_le_cfg_ServiceInstanceName;
void le_cfg_ConnectService(void);
extern const char* _batteryComponentRed_dhubIO_ServiceInstanceName;
const char** dhubIO_ServiceInstanceNamePtr = &_batteryComponentRed_dhubIO_ServiceInstanceName;
void dhubIO_ConnectService(void);
extern const char* _batteryComponentRed_ma_battery_ServiceInstanceName;
const char** ma_battery_ServiceInstanceNamePtr = &_batteryComponentRed_ma_battery_ServiceInstanceName;
void ma_battery_AdvertiseService(void);
extern const char* _batteryComponentRed_ma_adminbattery_ServiceInstanceName;
const char** ma_adminbattery_ServiceInstanceNamePtr = &_batteryComponentRed_ma_adminbattery_ServiceInstanceName;
void ma_adminbattery_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t batteryComponentRed_LogSession;
le_log_Level_t* batteryComponentRed_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _batteryComponentRed_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _batteryComponentRed_Init(void)
{
    LE_DEBUG("Initializing batteryComponentRed component library.");

    // Advertise server-side IPC interfaces.
    ma_battery_AdvertiseService();
    ma_adminbattery_AdvertiseService();

    // Connect client-side IPC interfaces.
    le_cfg_ConnectService();
    dhubIO_ConnectService();

    // Register the component with the Log Daemon.
    batteryComponentRed_LogSession = log_RegComponent("batteryComponentRed", &batteryComponentRed_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_batteryComponentRed_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
