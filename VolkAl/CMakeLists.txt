cmake_minimum_required(VERSION 3.12)
project(untitled11 C)

set(CMAKE_C_STANDARD 11)

add_library(untitled11 ../MR2018hh/VolkAl/Volkkk.c ../MR2018hh/VolkAl/VolkovaA.h)
add_executable(main Volkova.c)