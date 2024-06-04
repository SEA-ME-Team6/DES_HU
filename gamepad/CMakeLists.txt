cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(gamepad)

if (NOT TOP_CMAKE_FOUND)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

find_package(PythonLibs REQUIRED)

include_directories(
    ../src-gen/moving/core/common
    ../src-gen/moving/core/stub
    ../src-gen/moving/core/skel
    ../src-gen/light/core/common
    ../src-gen/light/core/proxy
    ${PYTHON_INCLUDE_DIRS}
)

add_executable(gamepad
    src/main.cpp
    src/gamepad.cpp
    src/gamepadsystem.cpp
    src/movingstubImpl.cpp
)

target_link_libraries(gamepad
    PRIVATE           CommonAPI
    ${PYTHON_LIBRARIES}
)

install(TARGETS       gamepad 
        DESTINATION   /usr/bin/DES3/gamepad
)
