cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(5555lib STATIC bibl.c)

add_executable(5555 zap.c)

target_link_libraries(5555 5555lib)