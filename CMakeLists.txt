cmake_minimum_required(VERSION 3.7)
project(QtPlugintest)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

# this variable allows cmake to automatically use the Qt preprocessor
set(CMAKE_AUTOMOC ON)
# set cpp standard to cpp 2011 and force the standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# set an alias as a collection of specified sourcefiles
set(SOURCE_FILES main.cpp PluginLoader.cpp PluginLoader.h IPlugin.h tests/TestCase.h tests/BenchmarkRun.cpp tests/BenchmarkRun.h tests/util/Stopwatch.cpp tests/util/Stopwatch.h tests/benchmarks/LoadAndUnloadBenchmark.h)
set(LIBRARY_SOURCES TestPlugin.cpp TestPlugin.h IPlugin.h tests/benchmarks/EnableAndDisableBenchmark.h)

# define project with named sourcefiles as an executable project
add_executable(QtPluginTest ${SOURCE_FILES})

# define project with named library sourcefiles as a library project
add_library(Plugin SHARED ${LIBRARY_SOURCES})

# Searching if libraries
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)


# linking the libraries Qt5::* to QtPluginTest
target_link_libraries(QtPluginTest Qt5::Widgets Qt5::Core)
# linking the libraries Qt5::* to Plugin
target_link_libraries(Plugin Qt5::Widgets Qt5::Core)

