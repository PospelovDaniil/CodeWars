cmake_minimum_required(VERSION 3.5)

project(Remove_exclamation_marks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Remove_exclamation_marks main.cpp)

install(TARGETS Remove_exclamation_marks
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
