cmake_minimum_required(VERSION 3.5)

project(Collinearity LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Collinearity main.cpp)

install(TARGETS Collinearity
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
