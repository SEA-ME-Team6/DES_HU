#ifndef BATTERYSYSTEM_HPP_
#define BATTERYSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "batterystubImpl.hpp"

using namespace v1::commonapi;

class BatterySystem {
public:
    BatterySystem();
    void setBattery(uint32_t batteryStatus);
    uint32_t getBattery();
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStubImpl> batteryService;
};

#endif 
