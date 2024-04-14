cmake_minimum_required(VERSION 3.26)
project(comparison_of_sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(comparison_of_sorting_algorithms main.cpp
        Array/array.cpp
        Array/array.h
        SortingAlgorithms/SortingAlgorithms.cpp
        SortingAlgorithms/SortingAlgorithms.h
        Menu/menu.cpp
        Menu/menu.h
        Menu/test.cpp
        Menu/test.h
        Menu/measurement.cpp
        Menu/measurement.h
)
