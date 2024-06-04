#include "gamepad.h"
#include "gamepadsystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    Gamepad* gamepad = new Gamepad;
    GamepadSystem* gamepadsystem = new GamepadSystem;

    float steering = 0;
    float throttle = 0;
    bool light = false;
    bool previous_light = false;
    
    while(true){
        gamepad->read_data(); 
    
        steering = gamepad->get_inputLX(); 
        throttle = gamepad->get_inputRY();
        light = gamepad->get_inputBY();

        std::cout << "Steering: " << steering << std::endl;
        std::cout << "Throttle: " << throttle << std::endl;
        std::cout << "Light: " << light << std::endl;

        gamepadsystem->setSteeringAttribute(steering);
        gamepadsystem->setThrottleAttribute(throttle);
        
        if (light != previous_light) {
            gamepadsystem->setLight(light);
            previous_light = light; 
        }
    }
    return 0;
}
