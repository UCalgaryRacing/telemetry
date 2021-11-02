

/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MANGOH_MUXCTRL_INTERFACE_H_INCLUDE_GUARD
#define MANGOH_MUXCTRL_INTERFACE_H_INCLUDE_GUARD


#include "legato.h"


//--------------------------------------------------------------------------------------------------
/**
 * Get the server service reference
 */
//--------------------------------------------------------------------------------------------------
le_msg_ServiceRef_t mangoh_muxCtrl_GetServiceRef
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the client session reference for the current message
 */
//--------------------------------------------------------------------------------------------------
le_msg_SessionRef_t mangoh_muxCtrl_GetClientSessionRef
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Initialize the server and advertise the service.
 */
//--------------------------------------------------------------------------------------------------
void mangoh_muxCtrl_AdvertiseService
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Disable UART 1
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllUart1Off
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Enable UART 1 on IoT slot 0
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot0Uart1On
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Enable UART 1 on IoT slot 1
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot1Uart1On
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Disable SPI
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllSpiOff
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Enable SPI on IoT slot 0
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot0Spi1On
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT1 SPI1 ON.
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot1Spi1On
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Disable UART 2
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllUart2Off
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Enable UART 2 on IoT slot 2
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot2Uart2On
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Enable UART 2 on the debug port
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Uart2DebugOn
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Connect the SDIO interface to the MicroSD card slot
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_SdioSelMicroSd
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Connect the SDIO interface to IoT slot 0
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_SdioSelIot0
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Disable the audio path
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_AudioDisable
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Route audio via a codec installed in IoT slot 0
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_AudioSelectIot0Codec
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Route audio via the codec on the mangOH board
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_AudioSelectOnboardCodec
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Route audio via a codec internal to the CF3 module
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_AudioSelectInternalCodec
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Take IoT slot 0 card out of reset
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot0DeassertReset
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Take IoT slot 1 card out of reset
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot1DeassertReset
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Take IoT slot 2 card out of reset
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot2DeassertReset
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Put Arduino in reset state
 *
 * @return
 *      - LE_FAULT
 *      - LE_UNSUPPORTED if the board doesn't have an Arduino
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_ArduinoAssertReset
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Put Arduino out of reset state
 *
 * @return
 *      - LE_FAULT
 *      - LE_UNSUPPORTED if the board doesn't have an Arduino
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_ArduinoDeassertReset
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Perform Arduino reset
 *
 * @return
 *      - LE_FAULT
 *      - LE_UNSUPPORTED if the board doesn't have an Arduino
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_ArduinoReset
(
    void
);


#endif // MANGOH_MUXCTRL_INTERFACE_H_INCLUDE_GUARD