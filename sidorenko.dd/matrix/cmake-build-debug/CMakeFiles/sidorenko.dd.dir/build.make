# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/sidorenko.dd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sidorenko.dd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sidorenko.dd.dir/flags.make

CMakeFiles/sidorenko.dd.dir/sid_main.c.obj: CMakeFiles/sidorenko.dd.dir/flags.make
CMakeFiles/sidorenko.dd.dir/sid_main.c.obj: ../sid_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sidorenko.dd.dir/sid_main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sidorenko.dd.dir\sid_main.c.obj   -c "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\sid_main.c"

CMakeFiles/sidorenko.dd.dir/sid_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sidorenko.dd.dir/sid_main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\sid_main.c" > CMakeFiles\sidorenko.dd.dir\sid_main.c.i

CMakeFiles/sidorenko.dd.dir/sid_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sidorenko.dd.dir/sid_main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\sid_main.c" -o CMakeFiles\sidorenko.dd.dir\sid_main.c.s

# Object files for target sidorenko.dd
sidorenko_dd_OBJECTS = \
"CMakeFiles/sidorenko.dd.dir/sid_main.c.obj"

# External object files for target sidorenko.dd
sidorenko_dd_EXTERNAL_OBJECTS =

sidorenko.dd.exe: CMakeFiles/sidorenko.dd.dir/sid_main.c.obj
sidorenko.dd.exe: CMakeFiles/sidorenko.dd.dir/build.make
sidorenko.dd.exe: libsid_matrix.a
sidorenko.dd.exe: CMakeFiles/sidorenko.dd.dir/linklibs.rsp
sidorenko.dd.exe: CMakeFiles/sidorenko.dd.dir/objects1.rsp
sidorenko.dd.exe: CMakeFiles/sidorenko.dd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sidorenko.dd.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sidorenko.dd.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sidorenko.dd.dir/build: sidorenko.dd.exe

.PHONY : CMakeFiles/sidorenko.dd.dir/build

CMakeFiles/sidorenko.dd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sidorenko.dd.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sidorenko.dd.dir/clean

CMakeFiles/sidorenko.dd.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix" "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix" "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\cmake-build-debug" "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\cmake-build-debug" "D:\Programms\111\High Code\lesson_7\MR2018-master\sidorenko.dd\matrix\cmake-build-debug\CMakeFiles\sidorenko.dd.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sidorenko.dd.dir/depend

