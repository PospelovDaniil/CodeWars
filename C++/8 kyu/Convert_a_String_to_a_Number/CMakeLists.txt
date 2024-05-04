cmake_minimum_required(VERSION 3.5)

project(Convert_a_String_to_a_Number LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Convert_a_String_to_a_Number main.cpp)

install(TARGETS Convert_a_String_to_a_Number
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
