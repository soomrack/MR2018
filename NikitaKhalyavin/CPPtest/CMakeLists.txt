cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_CPP_STANDARD 14)

add_library(NKhMatrLib MatrLib.cpp MatrLib.h)

add_executable(NKhCPPtest testex.cpp)
target_link_libraries(NKhCPPtest NKhMatrLib)

add_library(NKhTestLib tests/TestingLib.cpp tests/TestingLib.h)
target_link_libraries(NKhTestLib NKhMatrLib)

enable_testing()

add_executable(NKhInvertTest tests/testInvert.cpp)
target_link_libraries(NKhInvertTest NKhTestLib)

add_executable(NKhOneTest tests/testOne.cpp)
target_link_libraries(NKhOneTest NKhTestLib)

add_executable(NKhZeroTest tests/testZero.cpp)
target_link_libraries(NKhZeroTest NKhTestLib)

add_executable(NKhExpTest tests/testExp.cpp)
target_link_libraries(NKhExpTest NKhTestLib)

add_executable(NKhEigenTest tests/testEigen.cpp)
target_link_libraries(NKhEigenTest NKhTestLib)

add_test(NAME NKhInvert COMMAND NKhInvertTest)
add_test(NAME NKhOne COMMAND NKhOneTest)
add_test(NAME NKhZero COMMAND NKhZeroTest)
add_test(NAME NKhExp COMMAND NKhExpTest)
add_test(NAME NKhEigen COMMAND NKhEigenTest)




