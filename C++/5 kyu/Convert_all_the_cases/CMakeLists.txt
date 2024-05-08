cmake_minimum_required(VERSION 3.5)

project(Convert_all_the_cases LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Convert_all_the_cases main.cpp)

install(TARGETS Convert_all_the_cases
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
