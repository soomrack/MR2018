cmake_minimum_required(VERSION 3.13)
project(B_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(B_tree main.cpp B-tree.cpp B-tree.h)