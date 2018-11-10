cmake_minimum_required(VERSION 3.9)
project(VladBurin)

set(CMAKE_C_STANDARD 11)


add_executable(webserverVB webserverVB.c)
add_subdirectory(Matrix)
add_executable(mainV mainV.c)
