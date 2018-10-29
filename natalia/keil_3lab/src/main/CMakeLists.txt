cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        bitmagic.c
        bitmagic.h
        CMakeLists.txt
        eval1.c
        eval1.h
        main.c)
