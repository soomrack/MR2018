cmake_minimum_required(VERSION 3.9)
project(KomarovMatrixC)

set(CMAKE_C_STANDARD 11)

add_library(KomarovMatrixLibC STATIC komarovMatrixC.c)

add_executable(AlKomTestDeterminant tests/AlKomTestDeterminant.c)
add_executable(AlKomTestMatrix_Sum tests/AlKomTestMatrix_Sum.c)


target_link_libraries(AlKomTestDeterminant KomarovMatrixLibC)
target_link_libraries(AlKomTestMatrix_Sum KomarovMatrixLibC)


add_test(NAME DeterminantTest COMMAND AlKomTestDeterminant)
add_test(NAME Matrix_SumTest COMMAND AlKomTestMatrix_Sum)
