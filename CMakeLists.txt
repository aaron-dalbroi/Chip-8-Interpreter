cmake_minimum_required(VERSION 3.26)
project(Chip_8_Interpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chip_8_Interpreter chip8.c
        chip8.c
        chip8.h
        main.c)
