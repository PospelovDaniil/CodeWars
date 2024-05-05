cmake_minimum_required(VERSION 3.5)

project(1-800-CODE-WAR LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1-800-CODE-WAR main.cpp)

install(TARGETS 1-800-CODE-WAR
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
