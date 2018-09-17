cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC libraryvb.c)

add_executable(main notes.c)

target_link_libraries(main mylibrary)

include_directories(Artyrrr)
include_directories(kurshakov.ga)
include_directories(Nenahov)
include_directories(shayahmetov.rh)
include_directories(vorobieva.vb)
include_directories(librarypk)
include_directories(Elizaveta)
include_directories(VolkAl)
include_directories(ksenya)

add_subdirectory(Artyrrr)
add_subdirectory(kurshakov.ga)
add_subdirectory(Nenahov)
add_subdirectory(shayahmetov.rh)
add_subdirectory(vorobieva.vb)
add_subdirectory(librarypk)
add_subdirectory(Elizaveta)
add_subdirectory(VolkAl)
add_subdirectory(ksenya)
