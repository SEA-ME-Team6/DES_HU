cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(racer)

if (NOT TOP_CMAKE_FOUND)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

find_package(PythonLibs REQUIRED)

include_directories(
    src
    ../src-gen/gear/core/common
    ../src-gen/gear/core/stub
    ../src-gen/gear/core/skel
    ../src-gen/moving/core/common
    ../src-gen/moving/core/proxy
    ../src-gen/light/core/common
    ../src-gen/light/core/stub
    ../src-gen/light/core/skel
    ${PYTHON_INCLUDE_DIRS}
)

add_executable(racer
    src/main.cpp
    src/racer.cpp
    src/racersystem.cpp
    src/gearstubImpl.cpp
    src/lightstubImpl.cpp
)

target_link_libraries(racer
    PRIVATE           CommonAPI
    ${PYTHON_LIBRARIES}
)

install(TARGETS       racer 
        DESTINATION   /usr/bin/DES3/racer
)

