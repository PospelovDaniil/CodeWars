cmake_minimum_required(VERSION 3.5)

project(Human_Readable_Time LANGUAGES C)

add_executable(Human_Readable_Time main.c)

install(TARGETS Human_Readable_Time
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
