#include <iostream>
#include "gearstubImpl.hpp"

GearStubImpl::GearStubImpl() {

}

GearStubImpl::~GearStubImpl() {

}


uint8_t GearStubImpl::getGear() {
    return gear;
}

void GearStubImpl::gearselection(const std::shared_ptr<CommonAPI::ClientId> _client,
                                 uint8_t _gear,
                                 gearselectionReply_t _reply) {
    gear = _gear;
    _reply("success");
}