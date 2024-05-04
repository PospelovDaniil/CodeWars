cmake_minimum_required(VERSION 3.5)

project(Convert_a_Number_to_a_String LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Convert_a_Number_to_a_String main.cpp)

install(TARGETS Convert_a_Number_to_a_String
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
