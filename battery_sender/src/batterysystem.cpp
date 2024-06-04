#include "batterysystem.hpp"
#include <iostream>
#include <thread>

BatterySystem::BatterySystem(){
    runtime = CommonAPI::Runtime::get();
    batteryService = std::make_shared<BatteryStubImpl>();

    std::string domain = "local";

    //battery stub
    batteryService = std::make_shared<BatteryStubImpl>();
    std::string battery_instance = "BatteryStatus";
    std::string battery_connection = "service-battery";
    while (!runtime->registerService(domain, battery_instance, batteryService, battery_connection)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Battey Service!" << std::endl;

}

void BatterySystem::setBattery(uint32_t batteryStatus) {
    batteryService->setBatteryAttribute(batteryStatus);
}

