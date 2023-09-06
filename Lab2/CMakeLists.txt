cmake_minimum_required(VERSION 3.0)

project(Lab2)

find_package( Qt5Core )

add_executable(Lab2
    CPP.cpp 
    CSharp.cpp 
    Java.cpp
    Utils.cpp
    main.cpp
)

target_link_libraries( Lab2 Qt5::Core )