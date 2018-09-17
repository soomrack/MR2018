cmake_minimum_required(VERSION 3.12)
project(liza)

set(CMAKE_C_STANDARD 99)

add_executable(liza Emain.c)



add_library(mylib STATIC Elib.c)



target_link_libraries(liza mylib)