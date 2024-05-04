cmake_minimum_required(VERSION 3.5)

project(The_Vowel_Code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(The_Vowel_Code main.cpp)

install(TARGETS The_Vowel_Code
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
