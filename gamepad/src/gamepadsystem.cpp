#include "gamepadsystem.hpp"
#include <iostream>
#include <thread>

GamepadSystem::GamepadSystem(){
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //moving stub
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-moving";
    movingService = std::make_shared<MovingStubImpl>();
    while (!runtime->registerService(domain, moving_instance, movingService, moving_connection)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Moving Service!" << std::endl;

    //light client
    std::string light_instance = "LightStatus";
    std::string light_connection = "client-light";
    lightProxy = runtime->buildProxy<LightStatusProxy>(domain, light_instance, light_connection);
    while (!lightProxy->isAvailable()) {
        std::cout << "Waiting for Light service to become available." << std::endl;
    }    
    lightProxy->getLightAttribute().getChangedEvent().subscribe(
        [&](const bool& light_){
            light = light_;
        }
    );

}

void GamepadSystem::setSteeringAttribute(float steering){
    movingService->setSteeringAttribute(steering);
    std::cout<<"Sending Steering: " << steering << std::endl;
}

void GamepadSystem::setThrottleAttribute(float throttle){
    movingService->setThrottleAttribute(throttle);
    std::cout<<"Sending Throttle: " << throttle << std::endl;    
}

void GamepadSystem::setLight(bool light){
    CommonAPI::CallStatus callStatus;
    std::string replymessage;
    lightProxy->changedlight(light, callStatus, replymessage);
    std::cout << "callStatus: " << ((callStatus == CommonAPI::CallStatus::SUCCESS) ? "SUCCESS" : "NO_SUCCESS") << std::endl;
    std::cout << "response: " << replymessage << std::endl;
}
