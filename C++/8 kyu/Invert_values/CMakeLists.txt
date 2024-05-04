cmake_minimum_required(VERSION 3.5)

project(Invert_values LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Invert_values main.cpp)

install(TARGETS Invert_values
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
