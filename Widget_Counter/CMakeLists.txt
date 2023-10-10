cmake_minimum_required(VERSION 3.16)

project(Counter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Counter
    Widget_Counter.cpp
    main.cpp
)

target_link_libraries( Counter
    PRIVATE
    Qt5::Widgets
)