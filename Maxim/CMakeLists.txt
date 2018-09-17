cmake_minimum_required(VERSION 3.9)
	project(Project1)
	
	set(CMAKE_C_STANDARD 11)

add_executable(Project1 Project1/Structs.c)
	
	add_library(mybiblio STATIC Project1/fail2.c)
	
	target_link_libraries(Project1 mybiblio)
