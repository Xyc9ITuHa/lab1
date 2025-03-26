cmake_minimum_required(VERSION 3.30)
project(roundingSum)

set(CMAKE_CXX_STANDARD 23)

add_executable(roundingSum main.cpp
        money.h
        fileReading.cpp
        fileReading.h
        mapOperations.cpp
        mapOperations.h
        operatorOverloading.h)
