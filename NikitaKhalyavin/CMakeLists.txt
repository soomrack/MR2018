cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)

link_libraries(Ws2_32 wsock32)

add_executable(test256 win_webserver.c)



