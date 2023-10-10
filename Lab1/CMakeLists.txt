cmake_minimum_required(VERSION 3.16)

project(Lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Lab1
    File.cpp 
    Display.cpp 
    FileMonitor.cpp
    main.cpp
)

target_link_libraries( Lab1
    PRIVATE    
    Qt5::Core
)