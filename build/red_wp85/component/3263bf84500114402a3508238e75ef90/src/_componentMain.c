/*
 * AUTO-GENERATED _componentMain.c for the Sender component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

// Component log session variables.
le_log_SessionRef_t Sender_LogSession;
le_log_Level_t* Sender_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _Sender_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _Sender_Init(void)
{
    LE_DEBUG("Initializing Sender component library.");

    // Register the component with the Log Daemon.
    Sender_LogSession = log_RegComponent("Sender", &Sender_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_Sender_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
