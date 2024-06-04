cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(HUSystem)

set(CMAKE_CXX_STANDARD 11)
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

find_package(Qt5 REQUIRED COMPONENTS Core Quick)

include_directories(
    ../../../src-gen/gear/core/common
    ../../../src-gen/gear/core/proxy
    ../../../src-gen/rpm/core/common  
    ../../../src-gen/rpm/core/proxy
    ../../../src-gen/light/core/common
    ../../../src-gen/light/core/proxy
)

add_library(${PROJECT_NAME}
    SHARED
        src/husystem.cpp
        src/husystem_plugin.cpp
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE 
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        Qt5::Core 
        Qt5::Quick 
        Qt5::Gui 
        Qt5::Qml
        CommonAPI
)

set(PLUGIN_PATH /usr/lib/qml/User/${PROJECT_NAME})

install(TARGETS       ${PROJECT_NAME}
        DESTINATION   ${PLUGIN_PATH}
)

install(FILES         qmldir 
        DESTINATION   ${PLUGIN_PATH}
)
