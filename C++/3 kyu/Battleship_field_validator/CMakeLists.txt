cmake_minimum_required(VERSION 3.5)

project(Battleship_field_validator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Battleship_field_validator main.cpp)

install(TARGETS Battleship_field_validator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
