cmake_minimum_required(VERSION 3.9)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment_1
        interpreter.c
        interpreter.h
        shell.c
        shellmemory.c shell.h shellmemory.h)
