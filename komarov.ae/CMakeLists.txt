cmake_minimum_required(VERSION 3.9)
project(komarov.ae)

set(CMAKE_C_STANDARD 99)

link_libraries(Ws2_32 wsock32)

add_executable(komarov.ae komarov.c)


