cmake_minimum_required(VERSION 3.16)

project(Drawer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Drawer
    Widget_Drawer.cpp
    Figura.cpp
    Area.cpp
    main.cpp
)

target_link_libraries( Drawer
    PRIVATE
    Qt5::Widgets
)