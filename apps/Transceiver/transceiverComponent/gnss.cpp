#include "gnss.hpp"
#include "legato.h"
#include "interfaces.h"
#include <stdio.h>
#include <iostream>


void GNSS::startGNSS()
{
    // int32_t rate = 0;
    le_gnss_ConstellationBitMask_t constellationMask;
    // le_gnss_NmeaBitMask_t nmeaMask;
    // uint32_t ttff = 0;
    // le_posCtrl_Request();

    // printf("Start of startGNSS Function\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    LE_INFO("===========================Start of startGNSS Fucntion=====================================\n");
    
    // if(!(le_gnss_GetState() == 
    // {
    //     perror("GNSS STATE NOT READY\n");
    // }
    le_gnss_Enable();
	le_gnss_Start();

    le_gnss_State_t gnssState = le_gnss_GetState();
    std::cout << "gnss state: " << gnssState << std::endl;

    // le_gnss_GetAcquisitionRate(&rate);
    // int32_t gnssRate = le_gnss_GetAcquisitionRate(&rate);
    // std::cout << "=================gnss rate: " << gnssRate << std::endl;

    auto gnssConstellation = le_gnss_GetConstellation(&constellationMask);
    std::cout << "=================gnss consetllation: " << gnssConstellation << std::endl;

    printf("End of startGNSS Function\n");
}

// void GNSS::location(int32_t latitude, int32_t longitude, int32_t hAccuracy)
void GNSS::location()
{
    _positionSampleRef = le_gnss_GetLastSampleRef();

    //get location
    le_result_t result = le_gnss_GetLocation(_positionSampleRef, &_latitude, &_longitude, &_hAccuracy);
    std::cout << "############################ Result: " << result << std::endl;


    std::cout << "LAT, LONG, HACC: " << _latitude << " " << _longitude << " " << _hAccuracy << std::endl;

}

// void GNSS::positionHanlder(le_gnss_SampleRef_T _positionSampleRef, void* contextPtr)
void GNSS::positionHanlder()
{
    std::cout << ")(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$)(*!@#&$" << std::endl;
    int32_t x = 54321;
    unsigned char bytes[sizeof(int32_t)];
    for(unsigned int i = 0; i < sizeof(int32_t); i++)
    {
        bytes[i] = (x >> (i * 8)) & 0xFF;
        std::cout << "byte[ " << i << "]: " << bytes[i] << std::endl;
    }

    while(1)
    {
        _positionSampleRef = le_gnss_GetLastSampleRef();

        le_result_t result;
        result = le_gnss_GetEpochTime(_positionSampleRef, &_epochTime);
        if (result != LE_OK)
        {
            LE_INFO("Failed to get epoch time\n");
        }

        result = le_gnss_InjectUtcTime(_epochTime, 0);
        if (result != LE_OK)
        {
            LE_INFO("Failed to inject utc time");
        }

        // Get position state
        result = le_gnss_GetPositionState(_positionSampleRef, &_state);
        if (result != LE_OK)
        {
            LE_INFO("Failed to get position state");
        }

        // Get Location
        result = le_gnss_GetLocation(_positionSampleRef, &_latitude, &_longitude, &_hAccuracy);
        if (result != LE_OK)
        {
            LE_INFO("Failed to get location");
        }


        result = le_gnss_GetAltitude(_positionSampleRef, &_altitude, &_vAccuracy);

        le_gnss_ReleaseSampleRef(_positionSampleRef);

        debug();
        sleep(1);
    }
}

void GNSS::encodeGPSData()
{
    // struct can_frame canFrame;
    // //unhardcode this later
    // canFrame.can_id = 0x200;
    // canFrame.can_dlc = 8;  

    // unsigned char data[8];
    // data[0] = _latitude >> 24;
    // data[1] = _latitude >> 16;
    // data[2] = _latitude >> 8;
    // data[3] = _latitude;
    // data[4] = _longitude >> 24;
    // data[5] = _longitude >> 16;
    // data[6] = _longitude >> 8;
    // data[7] = _longitude;
    // data[8] = _altitude >> 8;
    // data[9] = _altitude;

    // std::cout << data << std::endl;
    // // std:: cout 
}

void* GNSS::positionThread(void *context)
{
    // //?
    // le_gnss_ConnectService();
    // _positionHandler = le_gnss_AddPositionHandler(positionHandler, NULL);
    // le_event_RunLoop();
    return NULL;
}

void GNSS::debug()
{
    std::cout << "positionSampleRef: " << _positionSampleRef << std::endl;
    std::cout << "epochTime: " << _epochTime << std::endl;
    std::cout << "state: " << _state << std::endl;
    std::cout << "lat: " << _latitude << std::endl;
    std::cout << "lng: " << _longitude << std::endl;
    std::cout << "hAcc: " << _hAccuracy << std::endl;
}