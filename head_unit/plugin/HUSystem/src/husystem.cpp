#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "husystem.h"

using namespace v1::commonapi;

HUSystem::HUSystem() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //gear client
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "client-gear";
    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, gear_instance, gear_connection);
    while (!gearProxy->isAvailable()) {
        std::cout << "Waiting for Gear service to become available." << std::endl;
    }

    gearProxy->getGearAttribute().getChangedEvent().subscribe(
        [&](const uint8_t& gear_){
            gear = gear_;
            emit gearChanged(); 
        }
    );

    //rpm client
    std::string rpm_instance = "RPMStatus";
    std::string rpm_connection = "client-rpm";
    rpmProxy = runtime->buildProxy<RPMStatusProxy>(domain, rpm_instance, rpm_connection);
    while (!rpmProxy->isAvailable()) {
        std::cout << "Waiting for RPM service to become available." << std::endl;
    }
    rpmProxy->getRpmAttribute().getChangedEvent().subscribe(
        [&](const float& rpm_){
            rpm_check = rpm_;
        }
    );
    
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
            emit lightChanged();
        }
    );
}


void HUSystem::changegear(quint8 gear){
    CommonAPI::CallStatus callStatus;
    std::string replymessage;
    gearProxy->gearselection(gear, callStatus, replymessage);
    std::cout << "callStatus: " << ((callStatus == CommonAPI::CallStatus::SUCCESS) ? "SUCCESS" : "NO_SUCCESS") << std::endl;
    std::cout << "response: " << replymessage << std::endl;
}

bool HUSystem::getLight() const {
    return light;
}

quint8 HUSystem::getGear() const {
    return gear;
}