cmake_minimum_required(VERSION 3.14)
project(DES3_HEAD_UNIT)

set(BUILD_COMMONAPI true CACHE BOOL "Build the CommonAPI")
set(TOP_CMAKE_FOUND true CACHE BOOL "Found Top of CMakeFIle")

# Commonapi Core
if(BUILD_COMMONAPI)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

# Commonapi Binding
# Make Shared Library
find_package(CommonAPI-SomeIP REQUIRED)
find_package(vsomeip3 REQUIRED)

include_directories(
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${VSOMEIP3_INCLUDE_DIRS}
    src-gen/battery/core/common
    src-gen/battery/core/proxy
    src-gen/battery/core/stub
    src-gen/battery/someip/common
    src-gen/battery/someip/proxy
    src-gen/battery/someip/stub
    src-gen/gear/core/common
    src-gen/gear/core/proxy
    src-gen/gear/core/stub
    src-gen/gear/someip/common
    src-gen/gear/someip/proxy
    src-gen/gear/someip/stub
    src-gen/light/core/common
    src-gen/light/core/proxy
    src-gen/light/core/stub
    src-gen/light/someip/common
    src-gen/light/someip/proxy
    src-gen/light/someip/stub
    src-gen/moving/core/common
    src-gen/moving/core/proxy
    src-gen/moving/core/stub
    src-gen/moving/someip/common
    src-gen/moving/someip/proxy
    src-gen/moving/someip/stub
    src-gen/rpm/core/common
    src-gen/rpm/core/proxy
    src-gen/rpm/core/stub
    src-gen/rpm/someip/common
    src-gen/rpm/someip/proxy
    src-gen/rpm/someip/stub
)

# battery stub
FILE(GLOB_RECURSE BATTERY_SOMEIP_STUB_LIB_SRCS 
    src-gen/battery/someip/stub/*.cpp
)
add_library(batterysomeipstub  SHARED
    ${BATTERY_SOMEIP_STUB_LIB_SRCS}
)
target_link_libraries(batterysomeipstub
    CommonAPI-SomeIP
    vsomeip3
)

# battery proxy
FILE(GLOB_RECURSE BATTERY_SOMEIP_PROXY_LIB_SRCS 
    src-gen/battery/someip/proxy/*.cpp
)
add_library(batterysomeipproxy  SHARED
    ${BATTERY_SOMEIP_PROXY_LIB_SRCS}
)
target_link_libraries(batterysomeipproxy
    CommonAPI-SomeIP
    vsomeip3
)

# gear stub
FILE(GLOB_RECURSE GEAR_SOMEIP_STUB_LIB_SRCS 
    src-gen/gear/someip/stub/*.cpp
)
add_library(gearsomeipstub  SHARED
    ${GEAR_SOMEIP_STUB_LIB_SRCS}
)
target_link_libraries(gearsomeipstub
    CommonAPI-SomeIP
    vsomeip3
)

# gear proxy
FILE(GLOB_RECURSE GEAR_SOMEIP_PROXY_LIB_SRCS 
    src-gen/gear/someip/proxy/*.cpp
)
add_library(gearsomeipproxy  SHARED
    ${GEAR_SOMEIP_PROXY_LIB_SRCS}
)
target_link_libraries(gearsomeipproxy
    CommonAPI-SomeIP
    vsomeip3
)

# light stub
FILE(GLOB_RECURSE LIGHT_SOMEIP_STUB_LIB_SRCS 
    src-gen/light/someip/stub/*.cpp
)
add_library(lightsomeipstub  SHARED
    ${LIGHT_SOMEIP_STUB_LIB_SRCS}
)
target_link_libraries(lightsomeipstub
    CommonAPI-SomeIP
    vsomeip3
)

# light proxy
FILE(GLOB_RECURSE LIGHT_SOMEIP_PROXY_LIB_SRCS 
    src-gen/light/someip/proxy/*.cpp
)
add_library(lightsomeipproxy  SHARED
    ${LIGHT_SOMEIP_PROXY_LIB_SRCS}
)
target_link_libraries(lightsomeipproxy
    CommonAPI-SomeIP
    vsomeip3
)

# moving stub
FILE(GLOB_RECURSE MOVING_SOMEIP_STUB_LIB_SRCS 
    src-gen/moving/someip/stub/*.cpp
)
add_library(movingsomeipstub  SHARED
    ${MOVING_SOMEIP_STUB_LIB_SRCS}
)
target_link_libraries(movingsomeipstub
    CommonAPI-SomeIP
    vsomeip3
)

# moving proxy
FILE(GLOB_RECURSE MOVING_SOMEIP_PROXY_LIB_SRCS 
    src-gen/moving/someip/proxy/*.cpp
)
add_library(movingsomeipproxy  SHARED
    ${MOVING_SOMEIP_PROXY_LIB_SRCS}
)
target_link_libraries(movingsomeipproxy
    CommonAPI-SomeIP
    vsomeip3
)

# rpm stub
FILE(GLOB_RECURSE RPM_SOMEIP_STUB_LIB_SRCS 
    src-gen/rpm/someip/stub/*.cpp
)
add_library(rpmsomeipstub  SHARED
    ${RPM_SOMEIP_STUB_LIB_SRCS}
)
target_link_libraries(rpmsomeipstub
    CommonAPI-SomeIP
    vsomeip3
)

# rpm proxy
FILE(GLOB_RECURSE RPM_SOMEIP_PROXY_LIB_SRCS 
    src-gen/rpm/someip/proxy/*.cpp
)
add_library(rpmsomeipproxy  SHARED
    ${RPM_SOMEIP_PROXY_LIB_SRCS}
)
target_link_libraries(rpmsomeipproxy
    CommonAPI-SomeIP
    vsomeip3
)


add_subdirectory(gamepad)
add_subdirectory(head_unit)
add_subdirectory(instrument_cluster)
add_subdirectory(racer)
add_subdirectory(rpm_sender)
add_subdirectory(battery_sender)
# add_subdirectory(Virtual_gamepad)

