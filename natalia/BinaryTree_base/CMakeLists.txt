cmake_minimum_required(VERSION 3.13)
project(BinaryTree_base)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinaryTree_base main.cpp base_tree.h binary_tree.h binary_tree.cpp base_tree.cpp RB_tree.cpp RB_tree.h)