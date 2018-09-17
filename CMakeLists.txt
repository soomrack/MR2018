cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC library.c)

add_executable(main CMakeLists.txt)

target_link_libraries(main mylibrary)

add_subdirectory(Artyrrr)
add_subdirectory(kurshakov.ga)
add_subdirectory(Nenahov)
add_subdirectory(shayahmetov.rh)
add_subdirectory(vorobieva.vb)
add_subdirectory(librarypk)
add_subdirectory(Elizaveta)
add_subdirectory(VolkAl)
add_subdirectory(ksenya)
