cmake_minimum_required(VERSION 3.12)
project(B_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(B_tree main.cpp B-treelibrary.cpp B-treelibrary.h)