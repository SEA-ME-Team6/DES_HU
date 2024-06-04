/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_COMMONAPI_MOVING_STATUS_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_MOVING_STATUS_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/MovingStatusStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename _Stub = ::v1::commonapi::MovingStatusStub, typename... _Stubs>
class MovingStatusSomeIPStubAdapterInternal
    : public virtual MovingStatusStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< MovingStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> MovingStatusSomeIPStubAdapterHelper;

    ~MovingStatusSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        MovingStatusSomeIPStubAdapterHelper::deinit();
    }

    void fireSteeringAttributeChanged(const float &_value);
    
    void fireThrottleAttributeChanged(const float &_value);
    
    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::MovingStatusStub,
        CommonAPI::Version
    > getMovingStatusInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::MovingStatusStub,
        float
    > getSteeringAttributeStubDispatcher;
    
    CommonAPI::SomeIP::SetObservableAttributeStubDispatcher<
        ::v1::commonapi::MovingStatusStub,
        float
    > setSteeringAttributeStubDispatcher;
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::MovingStatusStub,
        float
    > getThrottleAttributeStubDispatcher;
    
    CommonAPI::SomeIP::SetObservableAttributeStubDispatcher<
        ::v1::commonapi::MovingStatusStub,
        float
    > setThrottleAttributeStubDispatcher;
    
    MovingStatusSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        MovingStatusSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< MovingStatusStub>(_stub)),
        getMovingStatusInterfaceVersionStubDispatcher(&MovingStatusStub::lockInterfaceVersionAttribute, &MovingStatusStub::getInterfaceVersion, false, true),
        getSteeringAttributeStubDispatcher(
            &::v1::commonapi::MovingStatusStub::lockSteeringAttribute,
            &::v1::commonapi::MovingStatusStub::getSteeringAttribute,
            false,
            _stub->hasElement(0)),
        setSteeringAttributeStubDispatcher(
            &::v1::commonapi::MovingStatusStub::lockSteeringAttribute,
            &::v1::commonapi::MovingStatusStub::getSteeringAttribute,
            &MovingStatusStubRemoteEvent::onRemoteSetSteeringAttribute,
            &MovingStatusStubRemoteEvent::onRemoteSteeringAttributeChanged,
            &MovingStatusStubAdapter::fireSteeringAttributeChanged,
            false,
            _stub->hasElement(0))
        ,
        getThrottleAttributeStubDispatcher(
            &::v1::commonapi::MovingStatusStub::lockThrottleAttribute,
            &::v1::commonapi::MovingStatusStub::getThrottleAttribute,
            false,
            _stub->hasElement(1)),
        setThrottleAttributeStubDispatcher(
            &::v1::commonapi::MovingStatusStub::lockThrottleAttribute,
            &::v1::commonapi::MovingStatusStub::getThrottleAttribute,
            &MovingStatusStubRemoteEvent::onRemoteSetThrottleAttribute,
            &MovingStatusStubRemoteEvent::onRemoteThrottleAttributeChanged,
            &MovingStatusStubAdapter::fireThrottleAttributeChanged,
            false,
            _stub->hasElement(1))
    {
        MovingStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xbbc) }, &getSteeringAttributeStubDispatcher );
        MovingStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xbbd) }, &setSteeringAttributeStubDispatcher );
        MovingStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xbc6) }, &getThrottleAttributeStubDispatcher );
        MovingStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xbc7) }, &setThrottleAttributeStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>(0xFFFF, 0xFFFFFFFF, 0xFFFFFFFF);

        // Provided events/fields
        if (_stub->hasElement(0)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x80f6)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x80ec), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE);
            fireSteeringAttributeChanged(std::dynamic_pointer_cast< ::v1::commonapi::MovingStatusStub>(_stub)->getSteeringAttribute(itsClient));
        }

        if (_stub->hasElement(1)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x8100)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x80f6), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE);
            fireThrottleAttributeChanged(std::dynamic_pointer_cast< ::v1::commonapi::MovingStatusStub>(_stub)->getThrottleAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void MovingStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireSteeringAttributeChanged(const float &_value) {
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            float
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x80ec),
        false,
        _value
    );
}

template <typename _Stub, typename... _Stubs>
void MovingStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireThrottleAttributeChanged(const float &_value) {
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            float
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x80f6),
        false,
        _value
    );
}


template <typename _Stub, typename... _Stubs>
void MovingStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void MovingStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::commonapi::MovingStatusStub, typename... _Stubs>
class MovingStatusSomeIPStubAdapter
    : public MovingStatusSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    MovingStatusSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          MovingStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_Moving_Status_SOMEIP_STUB_ADAPTER_HPP_
