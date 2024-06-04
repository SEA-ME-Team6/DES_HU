#include "racersystem.hpp"

#include <iostream>
#include <thread>

RacerSystem::RacerSystem() {

    runtime = CommonAPI::Runtime::get();
    std::string domain = "local";

    //gear stub
    gearService = std::make_shared<GearStubImpl>();
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "service-gear";
    while (!runtime->registerService(domain, gear_instance, gearService, gear_connection)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Gear Service!" << std::endl;

    //moving proxy
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-moving";
    movingProxy = runtime->buildProxy<MovingStatusProxy>(domain, moving_instance, moving_connection);
    while (!movingProxy->isAvailable()) {
        std::cout << "Waiting for Moving service to become available." << std::endl;
    }
    movingProxy->getSteeringAttribute().getChangedEvent().subscribe(
        [&](const float& steering_){
            steering = steering_; 
        }
    );
    movingProxy->getThrottleAttribute().getChangedEvent().subscribe(
        [&](const float& throttle_){
            throttle = throttle_; 
        }
    );

    //ligth stub
    lightService = std::make_shared<LightStubImpl>();
    std::string light_instance = "LightStatus";
    std::string light_connection = "service-light";
    while (!runtime->registerService(domain, light_instance, lightService, light_connection)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Light Service!" << std::endl;
}

float RacerSystem::getSteering() {
    return steering;
}

float RacerSystem::getThrottle() {
    return throttle;
}

uint8_t RacerSystem::getGear(){
    return gearService->getGear();
}

bool RacerSystem::getLight(){
    return lightService->getLight();
}

void RacerSystem::setGearAttribute(uint8_t gear_){
    gearService->setGearAttribute(gear_);
}

void RacerSystem::setLightAttribute(bool light_){
    lightService->setLightAttribute(light_);
}