#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "husystem.h"

using namespace v1::commonapi;

HUSystem::HUSystem() {
    uint32_t ip_address = inet_addr("192.168.86.45");
    int lkas_port = 3333;
    int aeb_port = 3332;

    // Separate sockets for each port
    int lkas_server_fd = create_socket();
    int aeb_server_fd = create_socket();

    this->lkas_client_fd = setting_socket(lkas_server_fd, ip_address, lkas_port);
    this->aeb_client_fd = setting_socket(aeb_server_fd, ip_address, aeb_port);

    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //gear client
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "client-gear";
    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, gear_instance, gear_connection);
    // while (!gearProxy->isAvailable()) {
    //     std::cout << "Waiting for Gear service to become available." << std::endl;
    // }

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
    // while (!rpmProxy->isAvailable()) {
    //     std::cout << "Waiting for RPM service to become available." << std::endl;
    // }
    rpmProxy->getRpmAttribute().getChangedEvent().subscribe(
        [&](const float& rpm_){
            rpm_check = rpm_;
        }
    );
    
    //light client
    std::string light_instance = "LightStatus";
    std::string light_connection = "client-light";
    lightProxy = runtime->buildProxy<LightStatusProxy>(domain, light_instance, light_connection);
    // while (!lightProxy->isAvailable()) {
    //     std::cout << "Waiting for Light service to become available." << std::endl;
    // }   
    lightProxy->getLightAttribute().getChangedEvent().subscribe(
        [&](const bool& light_){
            light = light_;
            emit lightChanged();
        }
    );

}

void HUSystem::changegear(quint8 gear_){
    CommonAPI::CallStatus callStatus;
    std::string replymessage;
    gearProxy->gearselection(gear_, callStatus, replymessage);
    std::cout << "callStatus: " << ((callStatus == CommonAPI::CallStatus::SUCCESS) ? "SUCCESS" : "NO_SUCCESS") << std::endl;
    std::cout << "response: " << replymessage << std::endl;
}

void HUSystem::changelkas(){
    lkas = !lkas;
    emit lkasChanged();

    if(lkas) {lkas_activate = 1;}
    else {lkas_activate = 2;}
    
    send(this->lkas_client_fd, &lkas_activate, sizeof(lkas_activate), 0);

    std::cout << "LKAS PUSH" << std::endl;
}

void HUSystem::changeaeb(){
    aeb = !aeb;
    emit aebChanged();

    if(aeb) {aeb_activate = 1;}
    else {aeb_activate = 2;}

    send(this->aeb_client_fd, &aeb_activate, sizeof(aeb_activate), 0);

    std::cout << "AEB PUSH" << std::endl;
}

bool HUSystem::getLight() const {
    return light;
}

quint8 HUSystem::getGear() const {
    return gear;
}

quint8 HUSystem::getLkas() const {
    return lkas;
}

quint8 HUSystem::getAeb() const {
    return aeb;
}

int HUSystem::create_socket() {
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
    }

    return server_fd;
}

int HUSystem::setting_socket(int server_fd, uint32_t ip_address, int port) {
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    int client_fd;

    // Bind socket to port 8888
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = ip_address;
    server_addr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
    }
    std::cout << "Waiting for incoming connections...\n";

    client_addr_size = sizeof(client_addr);
    // Accept a connection
    if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_size)) < 0) {
        perror("Accept failed");
        close(server_fd);
    }
    std::cout << "Connection accepted.\n";

    return client_fd;
}