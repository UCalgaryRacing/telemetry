/*
 * AUTO-GENERATED _componentMain.c for the adminTool component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _adminTool_admin_ServiceInstanceName;
const char** admin_ServiceInstanceNamePtr = &_adminTool_admin_ServiceInstanceName;
void admin_ConnectService(void);
extern const char* _adminTool_query_ServiceInstanceName;
const char** query_ServiceInstanceNamePtr = &_adminTool_query_ServiceInstanceName;
void query_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t adminTool_LogSession;
le_log_Level_t* adminTool_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _adminTool_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _adminTool_Init(void)
{
    LE_DEBUG("Initializing adminTool component library.");

    // Connect client-side IPC interfaces.
    // 'admin' is [manual-start].
    // 'query' is [manual-start].

    // Register the component with the Log Daemon.
    adminTool_LogSession = log_RegComponent("adminTool", &adminTool_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_adminTool_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
