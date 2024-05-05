cmake_minimum_required(VERSION 3.5)

project(Is_a_number_prime LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Is_a_number_prime main.cpp)

install(TARGETS Is_a_number_prime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
