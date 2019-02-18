cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)


add_executable(NKhfind NKhMainFind.cpp)
add_library(NKhfindArray findInArray.cpp findInArray.h)
add_library(NKhsortArray ArraySort.cpp ArraySort.h)

add_executable(NKhTestChange tests/testChange.cpp)
add_executable(NKhTestSorts tests/allSortTest.cpp)

target_link_libraries(NKhfind NKhfindArray NKhsortArray)
target_link_libraries(NKhTestChange NKhfindArray NKhsortArray)
target_link_libraries(NKhTestSorts NKhsortArray)


enable_testing()

add_test(testChange NKhTestChange)
add_test(testSort NKhTestSort)