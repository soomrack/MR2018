cmake_minimum_required(VERSION 3.9)
project(VladBurin)

set(CMAKE_C_STANDARD 11)
enable_testing()

add_executable(webserverVB webserverVB.c)

add_executable(mainV mainV.c)
add_library(MatrixLibVB Matrix/MatrixOperations.c)


target_link_libraries(mainV MatrixLibVB)




add_executable(TestDeterminantVB Matrix/TestsVB/TestDeterminantVB.c)


add_test(NAME BurinTestDeterminant COMMAND TestDeterminantVB)


target_link_libraries(TestDeterminantVB MatrixLibVB)
