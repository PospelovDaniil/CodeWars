cmake_minimum_required(VERSION 3.5)

project(RGB_To_Hex_Conversion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RGB_To_Hex_Conversion main.cpp)

install(TARGETS RGB_To_Hex_Conversion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
