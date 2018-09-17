cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC library.c)

add_executable(main notes.c 5555/zap.c 5555/bibl.c 5555/bibl.h)
target_link_libraries(main mylibrary)