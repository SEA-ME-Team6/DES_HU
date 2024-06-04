cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(battery_sender)

if (NOT TOP_CMAKE_FOUND)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

find_package(PythonLibs REQUIRED)

include_directories(
    src
    ../src-gen/battery/core/common
    ../src-gen/battery/core/stub
    ../src-gen/battery/core/skel
    ${PYTHON_INCLUDE_DIRS}

)

add_executable(battery_sender
    src/main.cpp
    src/batterysystem.cpp
    src/batterystubImpl.cpp
    src/battery.cpp
)

target_link_libraries(battery_sender
    PRIVATE           CommonAPI
    ${PYTHON_LIBRARIES}
)

install(TARGETS       battery_sender 
        DESTINATION   /usr/bin/DES3/battery_sender
)
