/*
 * AUTO-GENERATED _componentMain.c for the avPublisher component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _avPublisher_le_avdata_ServiceInstanceName;
const char** le_avdata_ServiceInstanceNamePtr = &_avPublisher_le_avdata_ServiceInstanceName;
void le_avdata_ConnectService(void);
extern const char* _avPublisher_dhubIO_ServiceInstanceName;
const char** dhubIO_ServiceInstanceNamePtr = &_avPublisher_dhubIO_ServiceInstanceName;
void dhubIO_ConnectService(void);
extern const char* _avPublisher_dhubQuery_ServiceInstanceName;
const char** dhubQuery_ServiceInstanceNamePtr = &_avPublisher_dhubQuery_ServiceInstanceName;
void dhubQuery_ConnectService(void);
extern const char* _avPublisher_dhubAdmin_ServiceInstanceName;
const char** dhubAdmin_ServiceInstanceNamePtr = &_avPublisher_dhubAdmin_ServiceInstanceName;
void dhubAdmin_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t avPublisher_LogSession;
le_log_Level_t* avPublisher_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _avPublisher_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _avPublisher_Init(void)
{
    LE_DEBUG("Initializing avPublisher component library.");

    // Connect client-side IPC interfaces.
    le_avdata_ConnectService();
    dhubIO_ConnectService();
    dhubQuery_ConnectService();
    dhubAdmin_ConnectService();

    // Register the component with the Log Daemon.
    avPublisher_LogSession = log_RegComponent("avPublisher", &avPublisher_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_avPublisher_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
