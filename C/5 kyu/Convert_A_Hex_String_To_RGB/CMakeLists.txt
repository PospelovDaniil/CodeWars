cmake_minimum_required(VERSION 3.5)

project(Convert_A_Hex_String_To_RGB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Convert_A_Hex_String_To_RGB main.cpp)

install(TARGETS Convert_A_Hex_String_To_RGB
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
