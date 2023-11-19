cmake_minimum_required(VERSION 3.26)
project(porr_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(porr_project main.cpp
        des.h
        des.cpp
        permutations.h
        tests.h
        des3.h
        des3.cpp)
