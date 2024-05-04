cmake_minimum_required(VERSION 3.5)

project(All_Star_Code_Challenge_18 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(All_Star_Code_Challenge_18 main.cpp)

install(TARGETS All_Star_Code_Challenge_18
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
