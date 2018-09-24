cmake_minimum_required(VERSION 3.9)
project(komarov.ae)

set(CMAKE_C_STANDARD 11)

add_library(komarovlib STATIC komarov_library.c)

add_executable(komarov.ae komarov.c)
target_link_libraries(komarov.ae komarovlib)

