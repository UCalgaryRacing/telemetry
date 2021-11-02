/*
 * AUTO-GENERATED _componentMain.c for the position component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _position_le_posCtrl_ServiceInstanceName;
const char** le_posCtrl_ServiceInstanceNamePtr = &_position_le_posCtrl_ServiceInstanceName;
void le_posCtrl_ConnectService(void);
extern const char* _position_le_pos_ServiceInstanceName;
const char** le_pos_ServiceInstanceNamePtr = &_position_le_pos_ServiceInstanceName;
void le_pos_ConnectService(void);
extern const char* _position_dhubIO_ServiceInstanceName;
const char** dhubIO_ServiceInstanceNamePtr = &_position_dhubIO_ServiceInstanceName;
void dhubIO_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t position_LogSession;
le_log_Level_t* position_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _position_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _position_Init(void)
{
    LE_DEBUG("Initializing position component library.");

    // Connect client-side IPC interfaces.
    le_posCtrl_ConnectService();
    le_pos_ConnectService();
    dhubIO_ConnectService();

    // Register the component with the Log Daemon.
    position_LogSession = log_RegComponent("position", &position_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_position_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
