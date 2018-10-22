cmake_minimum_required(VERSION 3.3)

set(REPO ~/ClionProjects/repo)

project(Test)

project(Example)

include(CTest)
enable_testing()

set(gtest_disable_pthreads on) #needed in MinGW
#include(${REPO}/DownloadProject/DownloadProject.cmake)
include(ExternalProject)
ExternalProject_Add(googletest
        URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
        URL_HASH SHA1=f85f6d2481e2c6c4a18539e391aa4ea8ab0394af
        INSTALL_COMMAND ""
        )

ExternalProject_Get_Property(googletest binary_dir)
add_library(gtest UNKNOWN IMPORTED)
add_library(gtest_main UNKNOWN IMPORTED)
set_target_properties(gtest PROPERTIES
        IMPORTED_LOCATION ${binary_dir}/libgtest.a
        )
set_target_properties(gtest_main PROPERTIES
        IMPORTED_LOCATION ${binary_dir}/libgtest_main.a
        )
add_dependencies(gtest googletest)
add_dependencies(gtest_main googletest)

#add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

#set(test_SRCS ADD ALL TEST SOURCE FILES HERE)
add_executable(runUnitTests gtest_matrix_1_main.cpp ${test_SRCS})
add_executable(runmyTests test_matrix_1.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock core)
add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does
add_test(runmyTests runmyTests)