cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)

add_executable(NKhfind NKhMainFind.cpp trees.cpp trees.h)
add_library(NKhfindArray findInArray.cpp findInArray.h)
add_library(NKhsortArray ArraySort.cpp ArraySort.h)
add_library(NKhStructs structs.cpp structs.h)

add_library(NKhTreesParent trees/treesParent.cpp trees/treesParent.h)
add_library(NKhBinaryTree trees/binaryTree.cpp trees/binaryTree.h)
add_library(NKhRBTree trees/RBTree.cpp trees/RBTree.h)

add_executable(NKhTestChange tests/testChange.cpp)
add_executable(NKhTestSorts tests/allSortTest.cpp)
add_executable(NKhTestStructs tests/testStructs.cpp)

target_link_libraries(NKhBinaryTree NKhStructs NKhTreesParent)
target_link_libraries(NKhRBTree NKhStructs NKhTreesParent)

target_link_libraries(NKhfind NKhfindArray NKhsortArray NKhStructs NKhBinaryTree NKhRBTree)
target_link_libraries(NKhTestChange NKhfindArray NKhsortArray)
target_link_libraries(NKhTestSorts NKhsortArray)
target_link_libraries(NKhTestStructs NKhStructs)


enable_testing()


add_test(testSort NKhTestSorts)
add_test(testChange NKhTestChange)
add_test(testStructs NKhTestStructs)
