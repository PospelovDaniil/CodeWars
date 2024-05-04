cmake_minimum_required(VERSION 3.5)

project(Count_the_Monkeys LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Count_the_Monkeys main.cpp)

install(TARGETS Count_the_Monkeys
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
