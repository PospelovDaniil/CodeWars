cmake_minimum_required(VERSION 3.5)

project(Counting_sheep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Counting_sheep main.cpp)

install(TARGETS Counting_sheep
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
