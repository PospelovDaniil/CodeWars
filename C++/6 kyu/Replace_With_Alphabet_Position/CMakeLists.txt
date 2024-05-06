cmake_minimum_required(VERSION 3.5)

project(Replace_With_Alphabet_Position LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Replace_With_Alphabet_Position main.cpp)

install(TARGETS Replace_With_Alphabet_Position
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
