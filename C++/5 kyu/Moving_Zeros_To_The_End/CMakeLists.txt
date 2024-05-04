cmake_minimum_required(VERSION 3.5)

project(Moving_Zeros_To_The_End LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Moving_Zeros_To_The_End main.cpp)

install(TARGETS Moving_Zeros_To_The_End
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
