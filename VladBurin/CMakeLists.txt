cmake_minimum_required(VERSION 3.9)
project(VladBurin)

set(CMAKE_C_STANDARD 11)

set(ENABLETESTS TRUE)
add_executable(webserverVB webserverVB.c)

add_executable(mainV mainV.c)
add_executable(MainVBcpp MainVcpp.cpp)

add_library(MatrixLibVB Matrix/MatrixOperations.c)
add_library(MatrixVB Matrix/matrix.cpp)

target_link_libraries(mainV MatrixLibVB)
target_link_libraries(MainVBcpp MatrixVB)

target_link_libraries(MatrixLibVB m)
target_link_libraries(MatrixVB m)

if(ENABLETESTS)
enable_testing()

add_executable(TestDeterminantVB Matrix/TestsVB/TestDeterminantVB.cpp)
add_executable(TestTraceVB Matrix/TestsVB/TestTraceVB.cpp)
add_executable(TestSumVB Matrix/TestsVB/TestSumVB.cpp)
add_executable(TestMultScalarVB Matrix/TestsVB/TestMultScalarVB.cpp)
add_executable(TestTransVB Matrix/TestsVB/TestTransVB.cpp)
add_executable(TestMultVB Matrix/TestsVB/TestMultVB.cpp)
add_executable(TestPowerVB Matrix/TestsVB/TestPowerVB.cpp)
add_executable(TestInvertVB Matrix/TestsVB/TestInvertVB.cpp)
add_executable(TestOneVB Matrix/TestsVB/TestOneVB.cpp)
add_executable(TestZeroVB Matrix/TestsVB/TestZeroVB.cpp)


add_test(NAME BurinTestDeterminant COMMAND TestDeterminantVB)
add_test(NAME BurinTestTrace COMMAND TestTraceVB)
add_test(NAME BurinTestSum COMMAND TestSumVB)
add_test(NAME BurinTestMultScalar COMMAND TestMultScalarVB)
add_test(NAME BurinTestTrans COMMAND TestTransVB)
add_test(NAME BurinTestMult COMMAND TestMultVB)
add_test(NAME BurinTestPower COMMAND TestPowerVB)
add_test(NAME BurinTestInvert COMMAND TestInvertVB)
add_test(NAME BurinTestOne COMMAND TestOneVB)
add_test(NAME BurinTestZero COMMAND TestZeroVB)


target_link_libraries(TestDeterminantVB MatrixVB)
target_link_libraries(TestTraceVB MatrixVB)
target_link_libraries(TestSumVB MatrixVB)
target_link_libraries(TestMultScalarVB MatrixVB)
target_link_libraries(TestTransVB MatrixVB)
target_link_libraries(TestMultVB MatrixVB)
target_link_libraries(TestPowerVB MatrixVB)
target_link_libraries(TestInvertVB MatrixVB)
target_link_libraries(TestOneVB MatrixVB)
target_link_libraries(TestZeroVB MatrixVB)
endif()