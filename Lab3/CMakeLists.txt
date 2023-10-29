cmake_minimum_required(VERSION 3.16)

project(Lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5Charts)

add_executable(Lab3
    ChartData.cpp 
    ChartsView.cpp 
    FilesView.cpp
    IoC.cpp
    MainWindow.cpp
    Reader.cpp
    main.cpp
)

target_include_directories( Lab3
    PRIVATE
)

target_link_libraries( Lab3
    PRIVATE    
    Qt5::Core
    Qt5::Widgets
    Qt5::Charts
)