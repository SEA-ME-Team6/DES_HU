cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(instrument_cluster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if (NOT TOP_CMAKE_FOUND)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

include_directories(
    ../src-gen/rpm/core/common
    ../src-gen/rpm/core/proxy
    ../src-gen/battery/core/common
    ../src-gen/battery/core/proxy
    ../src-gen/gear/core/common
    ../src-gen/gear/core/proxy
)

add_executable(instrument_cluster
    src/main.cpp
    src/qml.qrc
    src/icsystem.cpp
)

target_link_libraries(instrument_cluster
    PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
    CommonAPI)


install(TARGETS       instrument_cluster 
        DESTINATION   /usr/bin/DES3/instrument_cluster
)
