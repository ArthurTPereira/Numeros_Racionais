cmake_minimum_required(VERSION 3.10)
project(Numeros_Racionais C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Numeros_Racionais
        main.c
        racional.c
        racional.h)
