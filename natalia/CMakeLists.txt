cmake_minimum_required(VERSION 3.12)
project(natalia)

set(CMAKE_CXX_STANDARD 14)

add_executable(natalia
        CMakeLists.txt
        server.c)
