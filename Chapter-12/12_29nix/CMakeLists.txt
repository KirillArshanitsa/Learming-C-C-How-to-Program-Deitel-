cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_C_STANDARD 11)


add_executable(untitled  main.c structs.h)
add_executable(untitled2 "toPostfix.cpp")
add_executable(untitled3 "simpletron.cpp")
