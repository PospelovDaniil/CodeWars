cmake_minimum_required(VERSION 3.5)

project(Compile_Time_Prime_Number_Detection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Compile_Time_Prime_Number_Detection main.cpp)

install(TARGETS Compile_Time_Prime_Number_Detection
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
