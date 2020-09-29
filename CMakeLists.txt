cmake_minimum_required(VERSION 3.17)
project(student_versions_real)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(student_versions_real
        Connect4.cpp
        Connect4.h
        constants.h
        main.cpp)
