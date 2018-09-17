cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibraryvb STATIC libraryvb.c)

add_executable(vorobieva notesvb.c)