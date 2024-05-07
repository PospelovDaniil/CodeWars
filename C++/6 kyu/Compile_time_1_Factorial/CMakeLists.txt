cmake_minimum_required(VERSION 3.5)

project(Compile_time_1_Factorial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Compile_time_1_Factorial main.cpp)

install(TARGETS Compile_time_1_Factorial
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
