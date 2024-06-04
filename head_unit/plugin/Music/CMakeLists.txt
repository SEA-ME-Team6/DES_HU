cmake_minimum_required(VERSION 3.14)

project(Music)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Multimedia QuickControls2)

add_library(${PROJECT_NAME}
    SHARED
        src/music.cpp
        src/music_plugin.cpp
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
        Qt5::Multimedia
        Qt5::QuickControls2
        CommonAPI
)

set(PLUGIN_PATH /usr/lib/qml/User/${PROJECT_NAME})

install(TARGETS       ${PROJECT_NAME}
        DESTINATION   ${PLUGIN_PATH}
)

install(FILES         qmldir 
        DESTINATION   ${PLUGIN_PATH}
)
