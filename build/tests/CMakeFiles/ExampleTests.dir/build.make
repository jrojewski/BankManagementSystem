# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zdunek/Desktop/Bank-managment-system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zdunek/Desktop/Bank-managment-system/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/ExampleTests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/ExampleTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/ExampleTests.dir/flags.make

tests/CMakeFiles/ExampleTests.dir/ExampleTests.cpp.o: tests/CMakeFiles/ExampleTests.dir/flags.make
tests/CMakeFiles/ExampleTests.dir/ExampleTests.cpp.o: ../tests/ExampleTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zdunek/Desktop/Bank-managment-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/ExampleTests.dir/ExampleTests.cpp.o"
	cd /home/zdunek/Desktop/Bank-managment-system/build/tests && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExampleTests.dir/ExampleTests.cpp.o -c /home/zdunek/Desktop/Bank-managment-system/tests/ExampleTests.cpp

tests/CMakeFiles/ExampleTests.dir/ExampleTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExampleTests.dir/ExampleTests.cpp.i"
	cd /home/zdunek/Desktop/Bank-managment-system/build/tests && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zdunek/Desktop/Bank-managment-system/tests/ExampleTests.cpp > CMakeFiles/ExampleTests.dir/ExampleTests.cpp.i

tests/CMakeFiles/ExampleTests.dir/ExampleTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExampleTests.dir/ExampleTests.cpp.s"
	cd /home/zdunek/Desktop/Bank-managment-system/build/tests && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zdunek/Desktop/Bank-managment-system/tests/ExampleTests.cpp -o CMakeFiles/ExampleTests.dir/ExampleTests.cpp.s

# Object files for target ExampleTests
ExampleTests_OBJECTS = \
"CMakeFiles/ExampleTests.dir/ExampleTests.cpp.o"

# External object files for target ExampleTests
ExampleTests_EXTERNAL_OBJECTS =

tests/ExampleTests: tests/CMakeFiles/ExampleTests.dir/ExampleTests.cpp.o
tests/ExampleTests: tests/CMakeFiles/ExampleTests.dir/build.make
tests/ExampleTests: lib/libgtest_maind.a
tests/ExampleTests: libExample.a
tests/ExampleTests: lib/libgtestd.a
tests/ExampleTests: tests/CMakeFiles/ExampleTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zdunek/Desktop/Bank-managment-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ExampleTests"
	cd /home/zdunek/Desktop/Bank-managment-system/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ExampleTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/ExampleTests.dir/build: tests/ExampleTests

.PHONY : tests/CMakeFiles/ExampleTests.dir/build

tests/CMakeFiles/ExampleTests.dir/clean:
	cd /home/zdunek/Desktop/Bank-managment-system/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/ExampleTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ExampleTests.dir/clean

tests/CMakeFiles/ExampleTests.dir/depend:
	cd /home/zdunek/Desktop/Bank-managment-system/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zdunek/Desktop/Bank-managment-system /home/zdunek/Desktop/Bank-managment-system/tests /home/zdunek/Desktop/Bank-managment-system/build /home/zdunek/Desktop/Bank-managment-system/build/tests /home/zdunek/Desktop/Bank-managment-system/build/tests/CMakeFiles/ExampleTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/ExampleTests.dir/depend

