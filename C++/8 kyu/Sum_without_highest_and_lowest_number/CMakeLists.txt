cmake_minimum_required(VERSION 3.5)

project(Sum_without_highest_and_lowest_number LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Sum_without_highest_and_lowest_number main.cpp)

install(TARGETS Sum_without_highest_and_lowest_number
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
