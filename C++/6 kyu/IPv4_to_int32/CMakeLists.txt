cmake_minimum_required(VERSION 3.5)

project(IPv4_to_int32 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(IPv4_to_int32 main.cpp)

install(TARGETS IPv4_to_int32
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
