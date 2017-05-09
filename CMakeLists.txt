cmake_minimum_required(VERSION 3.7)
project(QtPlugintest)


set(SOURCE_FILES main.cpp PluginLoader.cpp PluginLoader.h IPlugin.h)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(QtPluginTest ${SOURCE_FILES})
set(LIBRARY_SOURCES TestPlugin.cpp TestPlugin.h IPlugin.h)
add_library(Plugin SHARED ${LIBRARY_SOURCES})


find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

target_link_libraries(QtPluginTest Qt5::Widgets Qt5::Core)

target_link_libraries(Plugin Qt5::Widgets Qt5::Core)





if (CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(QtPluginTest dl)
endif (CMAKE_COMPILER_IS_GNUCXX)