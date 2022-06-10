#ifndef CAN_H
#define CAN_H

#include "../inc/httplib.h"
#include "../inc/json.hpp"
#include "sensor.hpp"
#include "constants.h"
#include "legato.h"
#include <time.h>
#include <thread>
#include <vector>
#include <chrono>
#include <future>
#include <net/if.h>
#include <linux/can.h>
#include <unordered_set>
#include <optional>
#include <vector>
#include <mutex>
#include <unordered_set>
#include <unordered_map>

using ReadCallback = std::function<void(unsigned int, std::vector<SensorVariantPair>)>;

class CanBus {
  private:
    std::unordered_map<unsigned int, std::vector<Sensor>> _sensorCanIdMap;
    std::unordered_map<unsigned char, Sensor> _sensorSmallIdMap;
    std::unordered_map<unsigned char, SensorDataVariant> _canBuffer;
    std::unordered_map<unsigned char, SensorDataVariant> _readBuffer;
    std::unordered_set<unsigned int> _translationIds{0x0cfff048, 0x0cfff148, 0x0cfff248, 0x0cfff348, 0x0cfff448, 0x0cfff548, 0x0cfff648, 0x0cfff748, 0x0cfff848, 0x0cfffA48, 0x0cfffB48, 0x0cfffc48, 0x0cfffd48, 0x0cfffe48, 0x0cffd048};
    unsigned char _frequency; // Is this the right type?
    bool _closed;
    int _canSocket;

    std::mutex _lock;

    /**
     * @brief
     */
    void translate(auto& data);

    /**
     * @brief 
     */
    void poll();

  public:
    CanBus() = delete;
    CanBus(std::vector<Sensor> sensors);

    /**
     * @brief 
     */
    bool initialize();

    /**
     * @brief 
     */
    void open();

    /**
     * @brief 
     */
    void readAndTrigger(ReadCallback callback);

    /**
     * @brief 
     */
    void close();
};

#endif