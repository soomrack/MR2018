cmake_minimum_required(VERSION 3.12)
project(NikitaKhalyavin)

set(CMAKE_CXX_STANDARD 14)
link_libraries(Ws2_32 wsock32)
add_executable(M win_webserver.c)

