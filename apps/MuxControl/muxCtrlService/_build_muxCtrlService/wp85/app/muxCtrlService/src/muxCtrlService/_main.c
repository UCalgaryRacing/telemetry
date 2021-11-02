
// Startup code for the executable 'muxCtrlService'.
// This is a generated file, do not edit.

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"
#include <dlfcn.h>


// Define IPC API interface names.
LE_SHARED const char* _muxCtrl_mangoh_muxCtrl_ServiceInstanceName = "mangoh_muxCtrl";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinUart1Enable_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinUart1Enable";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinUart1Select_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinUart1Select";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinSpiEnable_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinSpiEnable";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinSpiSelect_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinSpiSelect";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinUart2Enable_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinUart2Enable";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinUart2Select_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinUart2Select";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinPcmEnable_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinPcmEnable";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinPcmSelect_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinPcmSelect";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinSdioSelect_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinSdioSelect";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinPcmAnalogSelect_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinPcmAnalogSelect";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinIot0Reset_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinIot0Reset";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinIot1Reset_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinIot1Reset";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinIot2Reset_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinIot2Reset";
LE_SHARED const char* _muxCtrl_mangoh_gpioPinArduinoReset_ServiceInstanceName = "muxCtrlService.muxCtrl.mangoh_gpioPinArduinoReset";

// Define default component's log session variables.
LE_SHARED le_log_SessionRef_t muxCtrlService_exe_LogSession;
LE_SHARED le_log_Level_t* muxCtrlService_exe_LogLevelFilterPtr;

// Loads a library using dlopen().
__attribute__((unused)) static void LoadLib
(
    const char* libName
)
{
    dlopen(libName, RTLD_LAZY | RTLD_GLOBAL);
    const char* errorMsg = dlerror();
    LE_FATAL_IF(errorMsg != NULL,
                "Failed to load library '%s' (%s)",                libName,
                errorMsg);
}


int main(int argc, char* argv[])
{
    // Pass the args to the Command Line Arguments API.
    le_arg_SetArgs((size_t)argc, (char**)argv);
    // Make stdout line buffered so printf shows up in logs without flushing.
    setlinebuf(stdout);

    muxCtrlService_exe_LogSession = log_RegComponent("muxCtrlService_exe", &muxCtrlService_exe_LogLevelFilterPtr);

    // Connect to the log control daemon.
    // Note that there are some rare cases where we don't want the
    // process to try to connect to the Log Control Daemon (e.g.,
    // the Supervisor and the Service Directory shouldn't).
    // The NO_LOG_CONTROL macro can be used to control that.
    #ifndef NO_LOG_CONTROL
        log_ConnectToControlDaemon();
    #else
        LE_DEBUG("Not connecting to the Log Control Daemon.");
    #endif

    // Load dynamic libraries.
    LoadLib("libComponent_muxCtrl.so");

    // Set the Signal Fault handler
    le_sig_InstallShowStackHandler();

    // Set the Signal Term handler
    le_sig_InstallDefaultTermHandler();

    LE_DEBUG("== Starting Event Processing Loop ==");
    le_event_RunLoop();
    LE_FATAL("== SHOULDN'T GET HERE! ==");
}
