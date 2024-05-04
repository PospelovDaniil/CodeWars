cmake_minimum_required(VERSION 3.5)

project(Decode_the_Morse_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Decode_the_Morse_code main.cpp)

install(TARGETS Decode_the_Morse_code
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
