#include "lightstubImpl.hpp"

LightStubImpl::LightStubImpl(){

}

LightStubImpl::~LightStubImpl(){
    
}

bool LightStubImpl::getLight(){
    return light;
}

void LightStubImpl::changedlight(const std::shared_ptr<CommonAPI::ClientId> _client,
                                 bool _light,
                                 changedlightReply_t _reply) {
    light = _light;
    _reply("success");
}