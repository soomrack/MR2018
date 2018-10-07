cmake_minimum_required(VERSION 3.12)
project(ksenya)

set(CMAKE_C_STANDARD 99)

link_libraries(Ws2_32 wsock32)

add_executable(ksenya ksenya.c)



