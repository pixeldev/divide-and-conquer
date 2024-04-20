cmake_minimum_required(VERSION 3.28)
project(divide_y_venceras C)

set(CMAKE_C_STANDARD 23)

add_executable(divide_y_venceras main.c
        power.c
        power.h
        ternary.c
        ternary.h
        distances.c
        distances.h
        occurrences.c
        occurrences.h)
