/*
 * AUTO-GENERATED _componentMain.c for the ledServiceComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _ledServiceComponent_ma_led_ServiceInstanceName;
const char** ma_led_ServiceInstanceNamePtr = &_ledServiceComponent_ma_led_ServiceInstanceName;
void ma_led_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t ledServiceComponent_LogSession;
le_log_Level_t* ledServiceComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _ledServiceComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _ledServiceComponent_Init(void)
{
    LE_DEBUG("Initializing ledServiceComponent component library.");

    // Advertise server-side IPC interfaces.
    ma_led_AdvertiseService();

    // Register the component with the Log Daemon.
    ledServiceComponent_LogSession = log_RegComponent("ledServiceComponent", &ledServiceComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_ledServiceComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
