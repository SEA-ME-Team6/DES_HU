#ifndef LIGHTSTUBIMPL_HPP
#define LIGHTSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/LightStatusStubDefault.hpp>

class LightStubImpl : public v1_0::commonapi:: LightStatusStubDefault {
public:
    LightStubImpl();
    ~LightStubImpl();
    bool getLight();
    virtual void changedlight(const std::shared_ptr<CommonAPI::ClientId> _client,
                               bool _light,
                               changedlightReply_t _reply) override;

private:
    bool light = false;
};

#endif
