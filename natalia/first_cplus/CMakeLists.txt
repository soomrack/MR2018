cmake_minimum_required(VERSION 3.12)
project(first_cplus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
enable_testing()
add_executable(first_cplus src/matrixplus.cpp src/ClassMatrix.cpp src/ClassMatrix.h )

add_executable(mytest testmatrixplus/testmatrixplus.cpp)

add_test(NAME mytestmatrix COMMAND mytest)







