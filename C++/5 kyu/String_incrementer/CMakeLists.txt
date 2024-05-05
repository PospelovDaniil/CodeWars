cmake_minimum_required(VERSION 3.5)

project(String_incrementer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(String_incrementer main.cpp)

install(TARGETS String_incrementer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
