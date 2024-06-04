cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(rpm_sender)

if (NOT TOP_CMAKE_FOUND)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

include_directories(
    ../src-gen/rpm/core/common
    ../src-gen/rpm/core/stub
    ../src-gen/rpm/core/skel
)

add_executable(rpm_sender
    src/main.cpp
    src/canreceive.cpp
    src/rpmsystem.cpp
    src/rpmstubImpl.cpp
)

target_link_libraries(rpm_sender
    PRIVATE CommonAPI
)

install(TARGETS       rpm_sender 
        DESTINATION   /usr/bin/DES3/rpm_sender
)
