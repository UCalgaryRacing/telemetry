#include "legato.h"
#include "interfaces.h"
#include <linux/can.h>

class GNSS 
{
    private:
        int32_t _latitude;
        int32_t _longitude;
        int32_t _hAccuracy;
        int32_t _vAccuracy;
        int32_t _altitude;
        uint64_t _epochTime;
        le_gnss_SampleRef_t _positionSampleRef;
        static le_gnss_PositionHandlerRef_t _positionHandlerRef;
        le_gnss_FixState_t _state;

    public:
        void startGNSS();
        // void location(int32_t latitude, int32_t longitude, int32_t hAccuracy);
        void location();
        void positionHanlder();
        void* positionThread(void *context);
        void encodeGPSData();

        //temporary
        void debug();
};