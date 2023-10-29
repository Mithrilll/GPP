cmake_minimum_required(VERSION 3.16)

project(Lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Lab2
    CPP.cpp 
    CSharp.cpp 
    Java.cpp
    Utils.cpp
    main.cpp
)

target_link_libraries( Lab2 
    PRIVATE    
    Qt5::Core
)