# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = C:\Users\heckn\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5662.56\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\heckn\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5662.56\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Yahtzee.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Yahtzee.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Yahtzee.dir/flags.make

CMakeFiles/Yahtzee.dir/main.cpp.obj: CMakeFiles/Yahtzee.dir/flags.make
CMakeFiles/Yahtzee.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Yahtzee.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Yahtzee.dir\main.cpp.obj -c "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\main.cpp"

CMakeFiles/Yahtzee.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Yahtzee.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\main.cpp" > CMakeFiles\Yahtzee.dir\main.cpp.i

CMakeFiles/Yahtzee.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Yahtzee.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\main.cpp" -o CMakeFiles\Yahtzee.dir\main.cpp.s

# Object files for target Yahtzee
Yahtzee_OBJECTS = \
"CMakeFiles/Yahtzee.dir/main.cpp.obj"

# External object files for target Yahtzee
Yahtzee_EXTERNAL_OBJECTS =

Yahtzee.exe: CMakeFiles/Yahtzee.dir/main.cpp.obj
Yahtzee.exe: CMakeFiles/Yahtzee.dir/build.make
Yahtzee.exe: CMakeFiles/Yahtzee.dir/linklibs.rsp
Yahtzee.exe: CMakeFiles/Yahtzee.dir/objects1.rsp
Yahtzee.exe: CMakeFiles/Yahtzee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Yahtzee.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Yahtzee.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Yahtzee.dir/build: Yahtzee.exe

.PHONY : CMakeFiles/Yahtzee.dir/build

CMakeFiles/Yahtzee.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Yahtzee.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Yahtzee.dir/clean

CMakeFiles/Yahtzee.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee" "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee" "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\cmake-build-debug" "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\cmake-build-debug" "C:\Users\heckn\Documents\GitHub\eps11cpp\Max-Programming 12\Yahtzee\cmake-build-debug\CMakeFiles\Yahtzee.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Yahtzee.dir/depend

