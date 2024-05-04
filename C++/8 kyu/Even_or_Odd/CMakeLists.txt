cmake_minimum_required(VERSION 3.5)

project(Even_or_Odd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Even_or_Odd main.cpp)

install(TARGETS Even_or_Odd
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
