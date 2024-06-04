#ifndef RACERSYSTEM_HPP_
#define RACERSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/MovingStatusProxy.hpp>
#include "gearstubImpl.hpp"
#include "lightstubImpl.hpp"
#include "racer.h"

using namespace v1::commonapi;

class RacerSystem {
public:
    RacerSystem();

    float getSteering();
    float getThrottle();
    uint8_t getGear();
    bool getLight();

    void setGearAttribute(uint8_t gear_);
    void setLightAttribute(bool light_);
    
private:
    float steering = 0.0;
    float throttle = 0.0;
    bool light = false;
    
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStubImpl> gearService;
    std::shared_ptr<LightStubImpl> lightService;

    std::shared_ptr<MovingStatusProxy<>> movingProxy;
};

#endif 
