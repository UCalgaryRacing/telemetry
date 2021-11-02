/*
 * AUTO-GENERATED _componentMain.c for the periodicSensor component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _periodicSensor_dhubIO_ServiceInstanceName;
const char** dhubIO_ServiceInstanceNamePtr = &_periodicSensor_dhubIO_ServiceInstanceName;
void dhubIO_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t periodicSensor_LogSession;
le_log_Level_t* periodicSensor_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _periodicSensor_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _periodicSensor_Init(void)
{
    LE_DEBUG("Initializing periodicSensor component library.");

    // Connect client-side IPC interfaces.
    dhubIO_ConnectService();

    // Register the component with the Log Daemon.
    periodicSensor_LogSession = log_RegComponent("periodicSensor", &periodicSensor_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_periodicSensor_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
