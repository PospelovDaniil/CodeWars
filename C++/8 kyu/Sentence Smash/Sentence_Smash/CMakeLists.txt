cmake_minimum_required(VERSION 3.5)

project(Sentence_Smash LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Sentence_Smash main.cpp)

install(TARGETS Sentence_Smash
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
