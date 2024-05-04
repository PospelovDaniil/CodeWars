cmake_minimum_required(VERSION 3.5)

project(Powers_of_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Powers_of_2 main.cpp)

install(TARGETS Powers_of_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
