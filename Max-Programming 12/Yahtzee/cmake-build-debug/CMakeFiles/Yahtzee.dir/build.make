# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.jceDSz2Vhn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.jceDSz2Vhn/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Yahtzee.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Yahtzee.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Yahtzee.dir/flags.make

CMakeFiles/Yahtzee.dir/main.cpp.o: CMakeFiles/Yahtzee.dir/flags.make
CMakeFiles/Yahtzee.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.jceDSz2Vhn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Yahtzee.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Yahtzee.dir/main.cpp.o -c /tmp/tmp.jceDSz2Vhn/main.cpp

CMakeFiles/Yahtzee.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Yahtzee.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.jceDSz2Vhn/main.cpp > CMakeFiles/Yahtzee.dir/main.cpp.i

CMakeFiles/Yahtzee.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Yahtzee.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.jceDSz2Vhn/main.cpp -o CMakeFiles/Yahtzee.dir/main.cpp.s

CMakeFiles/Yahtzee.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Yahtzee.dir/main.cpp.o.requires

CMakeFiles/Yahtzee.dir/main.cpp.o.provides: CMakeFiles/Yahtzee.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Yahtzee.dir/build.make CMakeFiles/Yahtzee.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Yahtzee.dir/main.cpp.o.provides

CMakeFiles/Yahtzee.dir/main.cpp.o.provides.build: CMakeFiles/Yahtzee.dir/main.cpp.o


# Object files for target Yahtzee
Yahtzee_OBJECTS = \
"CMakeFiles/Yahtzee.dir/main.cpp.o"

# External object files for target Yahtzee
Yahtzee_EXTERNAL_OBJECTS =

Yahtzee: CMakeFiles/Yahtzee.dir/main.cpp.o
Yahtzee: CMakeFiles/Yahtzee.dir/build.make
Yahtzee: CMakeFiles/Yahtzee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.jceDSz2Vhn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Yahtzee"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Yahtzee.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Yahtzee.dir/build: Yahtzee

.PHONY : CMakeFiles/Yahtzee.dir/build

CMakeFiles/Yahtzee.dir/requires: CMakeFiles/Yahtzee.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Yahtzee.dir/requires

CMakeFiles/Yahtzee.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Yahtzee.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Yahtzee.dir/clean

CMakeFiles/Yahtzee.dir/depend:
	cd /tmp/tmp.jceDSz2Vhn/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.jceDSz2Vhn /tmp/tmp.jceDSz2Vhn /tmp/tmp.jceDSz2Vhn/cmake-build-debug /tmp/tmp.jceDSz2Vhn/cmake-build-debug /tmp/tmp.jceDSz2Vhn/cmake-build-debug/CMakeFiles/Yahtzee.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Yahtzee.dir/depend

