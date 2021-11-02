/*
 * AUTO-GENERATED _componentMain.c for the imu component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _imu_le_adc_ServiceInstanceName;
const char** le_adc_ServiceInstanceNamePtr = &_imu_le_adc_ServiceInstanceName;
void le_adc_ConnectService(void);
extern const char* _imu_dhubIO_ServiceInstanceName;
const char** dhubIO_ServiceInstanceNamePtr = &_imu_dhubIO_ServiceInstanceName;
void dhubIO_ConnectService(void);
extern const char* _imu_imu_ServiceInstanceName;
const char** imu_ServiceInstanceNamePtr = &_imu_imu_ServiceInstanceName;
void imu_AdvertiseService(void);
extern const char* _imu_temperature_ServiceInstanceName;
const char** temperature_ServiceInstanceNamePtr = &_imu_temperature_ServiceInstanceName;
void temperature_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t imu_LogSession;
le_log_Level_t* imu_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _imu_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _imu_Init(void)
{
    LE_DEBUG("Initializing imu component library.");

    // Advertise server-side IPC interfaces.
    imu_AdvertiseService();
    temperature_AdvertiseService();

    // Connect client-side IPC interfaces.
    le_adc_ConnectService();
    dhubIO_ConnectService();

    // Register the component with the Log Daemon.
    imu_LogSession = log_RegComponent("imu", &imu_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_imu_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
