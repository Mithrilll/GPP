cmake_minimum_required(VERSION 3.16)

project(IOC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(IOC
    main.cpp
)

target_include_directories( IOC
    PRIVATE
)

target_link_libraries( IOC
    PRIVATE    
    Qt5::Core
)