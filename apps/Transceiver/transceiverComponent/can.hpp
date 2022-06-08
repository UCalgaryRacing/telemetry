#ifndef CAN_H
#define CAN_H

#include "sensor.hpp"
#include <optional>
#include <vector>
#include <mutex>
#include <unordered_map>

using ReadCallback = std::function<void(unsigned int, std::vector<SensorVariantPair>)>

class CanBus {
  private:
    std::unordered_map<unsigned int, Sensor> _sensorCanIdMap;
    std::unordered_map<unsigned char, Sensor> _sensorSmallIdMap;
    std::unordered_map<unsigned char, SensorDataVariant> _canBuffer;
    std::unordered_map<unsigned char, SensorDataVariant> _readBuffer;
    ReadCallback _callback;
    unsigned char _frequency; // Is this the right type?
    bool _closed;
    int _canSocket;

    std::mutex _lock;

    /**
     * @brief 
     */
    void pollCanBus();

  public:
    CanBus() = delete;
    CanBus(std::vector<Sensor> &sensors, ReadCallback callback);

    /**
     * @brief 
     */
    bool initializeCanBus();

    /**
     * @brief 
     */
    void openCanBus();

    /**
     * @brief 
     */
    void readCanBus();

    /**
     * @brief 
     */
    void closeCanBus() noexcept;
};

#endif