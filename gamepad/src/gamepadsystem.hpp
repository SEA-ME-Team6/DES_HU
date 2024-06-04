#ifndef GAMEPADSYSTEM_HPP_
#define GAMEPADSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/LightStatusProxy.hpp>
#include "movingstubImpl.hpp"

using namespace v1::commonapi;

class GamepadSystem {
public:
    GamepadSystem();
    void setSteeringAttribute(float steering);
    void setThrottleAttribute(float throttle);
    void setLight(bool light);
    
private:
    bool light = false;
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<MovingStubImpl> movingService;
    std::shared_ptr<LightStatusProxy<>> lightProxy;
    
};

#endif 
