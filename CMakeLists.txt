cmake_minimum_required(VERSION 3.23)
project(Regresi_Linear_Berganda C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Regresi_Linear_Berganda
        main.c
        statistics.c statistics.h
        regression.c regression.h)
