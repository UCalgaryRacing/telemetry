/*
 * AUTO-GENERATED _componentMain.c for the pressure component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _pressure_dhubIO_ServiceInstanceName;
const char** dhubIO_ServiceInstanceNamePtr = &_pressure_dhubIO_ServiceInstanceName;
void dhubIO_ConnectService(void);
extern const char* _pressure_pressure_ServiceInstanceName;
const char** pressure_ServiceInstanceNamePtr = &_pressure_pressure_ServiceInstanceName;
void pressure_AdvertiseService(void);
extern const char* _pressure_temperature_ServiceInstanceName;
const char** temperature_ServiceInstanceNamePtr = &_pressure_temperature_ServiceInstanceName;
void temperature_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t pressure_LogSession;
le_log_Level_t* pressure_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _pressure_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _pressure_Init(void)
{
    LE_DEBUG("Initializing pressure component library.");

    // Advertise server-side IPC interfaces.
    pressure_AdvertiseService();
    temperature_AdvertiseService();

    // Connect client-side IPC interfaces.
    dhubIO_ConnectService();

    // Register the component with the Log Daemon.
    pressure_LogSession = log_RegComponent("pressure", &pressure_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_pressure_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
