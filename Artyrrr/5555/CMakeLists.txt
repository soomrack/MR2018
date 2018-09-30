cmake_minimum_required(VERSION 3.9)
project(Artyrrr)

set(CMAKE_C_STANDARD 11)

add_executable(Artyrrr notes.c 5555/zap.c 5555/bibl.c 5555/bibl.h)

add_library(ArtyrrrLibrary STATIC myibrary.с!)

target_link_libraries(Artyrrr Artyrrrlib)
