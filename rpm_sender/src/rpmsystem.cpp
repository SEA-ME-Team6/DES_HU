#include "rpmsystem.hpp"

#include <iostream>
#include <thread>

RPMSystem::RPMSystem() {
    runtime = CommonAPI::Runtime::get();
    std::string domain = "local";

    //rpm stub
    rpmservice = std::make_shared<RPMStubImpl>();
    std::string rpm_instance = "RPMStatus";
    std::string rpm_connection = "service-rpm";
    while (!runtime->registerService(domain, rpm_instance, rpmservice, rpm_connection)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered RPM Service!" << std::endl;
}

void RPMSystem::setRPM(float rpm) {
    std::cout << "RPN Sender set rpm: " << rpm << std::endl;
    rpmservice->setRpmAttribute(rpm);
}
