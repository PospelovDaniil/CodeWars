cmake_minimum_required(VERSION 3.5)

project(MakeUpperCase LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MakeUpperCase main.cpp)

install(TARGETS MakeUpperCase
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
