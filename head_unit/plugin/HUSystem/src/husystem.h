#ifndef HEADUNITSYSTEM_HPP
#define HEADUNITSYSTEM_HPP

#include <memory>
#include <QObject>
#include <stdint.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include <v1/commonapi/RPMStatusProxy.hpp>
#include <v1/commonapi/LightStatusProxy.hpp>

using namespace v1::commonapi;

class HUSystem: public QObject{
    Q_OBJECT
    Q_PROPERTY(bool light READ getLight NOTIFY lightChanged)
    Q_PROPERTY(quint8 gear READ getGear NOTIFY gearChanged)

public:
    HUSystem();

    bool getLight() const;
    quint8 getGear() const;

public slots:
    void changegear(quint8 gear);

signals:
    void lightChanged();
    void gearChanged();

private:
    float rpm_check = 0.0;
    bool light = false;
    quint8 gear = 0;
    
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
    std::shared_ptr<RPMStatusProxy<>> rpmProxy;
    std::shared_ptr<LightStatusProxy<>> lightProxy;
};

#endif // GEARCLIENT_HPP