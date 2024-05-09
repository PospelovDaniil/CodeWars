cmake_minimum_required(VERSION 3.5)

project(A_Simplistic_TCP_Finite_State_Machine_FSM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(A_Simplistic_TCP_Finite_State_Machine_FSM main.cpp)

install(TARGETS A_Simplistic_TCP_Finite_State_Machine_FSM
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
