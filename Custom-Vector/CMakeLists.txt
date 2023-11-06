cmake_minimum_required(VERSION 3.24)
project(Custom_Vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Custom_Vector
        exceptions.h
        main.cpp
        YFVector.cpp
        YFVector.h)
