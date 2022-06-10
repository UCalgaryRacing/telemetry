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
    std::unordered_set<unsigned int> _translationIds{11, 12, 14, 15, 16, 17, 18, 13, 19, 20, 21, 22, 23, 24, 25, 8, 27, 28, 9, 10, 29, 30, 26, 31, 32, 33, 34, 35, 36, 37, 38};
    unsigned char _frequency; // Is this the right type?
    bool _closed;
    int _canSocket;

    std::mutex _lock;

    /**
     * @brief
     */
    void translate(auto& data);

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
    bool engineStarted();

    /**
     * @brief 
     */
    void open();

    /**
     * @brief 
     */
    void poll();

    /**
     * @brief 
     */
    void decimateFrequency(ReadCallback callback);

    /**
     * @brief 
     */
    void close();
};

#endif