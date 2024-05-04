cmake_minimum_required(VERSION 3.5)

project(Count_Odd_Numbers_below_n LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Count_Odd_Numbers_below_n main.cpp)

install(TARGETS Count_Odd_Numbers_below_n
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
