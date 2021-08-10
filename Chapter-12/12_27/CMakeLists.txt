cmake_minimum_required(VERSION 3.19)
project(projectC)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectC  main.cpp structs.h)
add_executable(projectC2 "toPostfix.cpp")
