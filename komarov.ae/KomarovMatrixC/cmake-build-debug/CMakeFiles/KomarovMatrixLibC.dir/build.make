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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/KomarovMatrixLibC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KomarovMatrixLibC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KomarovMatrixLibC.dir/flags.make

CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.obj: CMakeFiles/KomarovMatrixLibC.dir/flags.make
CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.obj: ../komarovMatrixC.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\KomarovMatrixLibC.dir\komarovMatrixC.c.obj   -c "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\komarovMatrixC.c"

CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\komarovMatrixC.c" > CMakeFiles\KomarovMatrixLibC.dir\komarovMatrixC.c.i

CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\komarovMatrixC.c" -o CMakeFiles\KomarovMatrixLibC.dir\komarovMatrixC.c.s

# Object files for target KomarovMatrixLibC
KomarovMatrixLibC_OBJECTS = \
"CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.obj"

# External object files for target KomarovMatrixLibC
KomarovMatrixLibC_EXTERNAL_OBJECTS =

libKomarovMatrixLibC.a: CMakeFiles/KomarovMatrixLibC.dir/komarovMatrixC.c.obj
libKomarovMatrixLibC.a: CMakeFiles/KomarovMatrixLibC.dir/build.make
libKomarovMatrixLibC.a: CMakeFiles/KomarovMatrixLibC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libKomarovMatrixLibC.a"
	$(CMAKE_COMMAND) -P CMakeFiles\KomarovMatrixLibC.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\KomarovMatrixLibC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KomarovMatrixLibC.dir/build: libKomarovMatrixLibC.a

.PHONY : CMakeFiles/KomarovMatrixLibC.dir/build

CMakeFiles/KomarovMatrixLibC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KomarovMatrixLibC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/KomarovMatrixLibC.dir/clean

CMakeFiles/KomarovMatrixLibC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC" "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC" "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\cmake-build-debug" "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\cmake-build-debug" "C:\Users\al.kom\YandexDisk\Monday C.Cpp\KomarovMatrixC\cmake-build-debug\CMakeFiles\KomarovMatrixLibC.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/KomarovMatrixLibC.dir/depend

