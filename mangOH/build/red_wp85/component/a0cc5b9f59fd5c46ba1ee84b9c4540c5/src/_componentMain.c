/*
 * AUTO-GENERATED _componentMain.c for the light component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _light_le_adc_ServiceInstanceName;
const char** le_adc_ServiceInstanceNamePtr = &_light_le_adc_ServiceInstanceName;
void le_adc_ConnectService(void);
extern const char* _light_dhubIO_ServiceInstanceName;
const char** dhubIO_ServiceInstanceNamePtr = &_light_dhubIO_ServiceInstanceName;
void dhubIO_ConnectService(void);
extern const char* _light_light_ServiceInstanceName;
const char** light_ServiceInstanceNamePtr = &_light_light_ServiceInstanceName;
void light_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t light_LogSession;
le_log_Level_t* light_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _light_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _light_Init(void)
{
    LE_DEBUG("Initializing light component library.");

    // Advertise server-side IPC interfaces.
    light_AdvertiseService();

    // Connect client-side IPC interfaces.
    le_adc_ConnectService();
    dhubIO_ConnectService();

    // Register the component with the Log Daemon.
    light_LogSession = log_RegComponent("light", &light_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_light_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
