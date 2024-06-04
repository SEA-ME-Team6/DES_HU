#include "battery.h"
#include "batterysystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    Battery* battery = new Battery;
    BatterySystem* batterysystem = new BatterySystem;
    uint32_t batterystatus = 0;

    while(true){
        batterystatus = battery->get_battery_voltage();
        std::cout << "battery: " << batterystatus << std::endl;
        batterysystem->setBattery(batterystatus);
        sleep(0.5);
    }
    
    return 0;
}
