#ifndef HEADUNITSYSTEM_HPP
#define HEADUNITSYSTEM_HPP

#include <memory>
#include <QObject>
#include <stdint.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include <v1/commonapi/RPMStatusProxy.hpp>
#include <v1/commonapi/LightStatusProxy.hpp>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace v1::commonapi;

class HUSystem: public QObject{
    Q_OBJECT
    Q_PROPERTY(bool light READ getLight NOTIFY lightChanged)
    Q_PROPERTY(quint8 gear READ getGear NOTIFY gearChanged)
    Q_PROPERTY(quint8 lkas READ getLkas NOTIFY lkasChanged)
    Q_PROPERTY(quint8 aeb READ getAeb NOTIFY aebChanged)

public:
    HUSystem();

    bool getLight() const;
    quint8 getGear() const;
    quint8 getLkas() const;
    quint8 getAeb() const;

public slots:
    void changegear(quint8 gear);
    void changelkas();
    void changeaeb();

signals:
    void lightChanged();
    void gearChanged();
    void lkasChanged();
    void aebChanged();

private:
    int create_socket();
    int setting_socket(int server_fd, uint32_t ip_address, int port);

    float rpm_check = 0.0;
    bool light = false;
    quint8 gear = 0;
    bool lkas = false;
    bool aeb = false;
    
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
    std::shared_ptr<RPMStatusProxy<>> rpmProxy;
    std::shared_ptr<LightStatusProxy<>> lightProxy;

    int lkas_client_fd, aeb_client_fd;
    quint8 lkas_activate, aeb_activate;
};

#endif // GEARCLIENT_HPP