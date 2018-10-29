cmake_minimum_required(VERSION 3.12)
project(keil_3lab)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_executable(keil_lab src/main/main.c)
add_executable(keil_lab_eval src/main/eval1.c)
#add_executable(keil_lab_eval1 src/main/eval1.h)
add_executable(Testeval .test/tests.c)

add_test(NAME mytesteval COMMAND Testeval)


