# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

#Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /hw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /hw/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/sync_tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/sync_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/sync_tests.dir/flags.make

tests/CMakeFiles/sync_tests.dir/sync_test.cpp.o: tests/CMakeFiles/sync_tests.dir/flags.make
tests/CMakeFiles/sync_tests.dir/sync_test.cpp.o: ../tests/sync_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/hw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/sync_tests.dir/sync_test.cpp.o"
	cd /hw/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sync_tests.dir/sync_test.cpp.o -c /hw/tests/sync_test.cpp

tests/CMakeFiles/sync_tests.dir/sync_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sync_tests.dir/sync_test.cpp.i"
	cd /hw/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /hw/tests/sync_test.cpp > CMakeFiles/sync_tests.dir/sync_test.cpp.i

tests/CMakeFiles/sync_tests.dir/sync_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sync_tests.dir/sync_test.cpp.s"
	cd /hw/build/tests && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /hw/tests/sync_test.cpp -o CMakeFiles/sync_tests.dir/sync_test.cpp.s

# Object files for target sync_tests
sync_tests_OBJECTS = \
"CMakeFiles/sync_tests.dir/sync_test.cpp.o"

# External object files for target sync_tests
sync_tests_EXTERNAL_OBJECTS =

tests/sync_tests: tests/CMakeFiles/sync_tests.dir/sync_test.cpp.o
tests/sync_tests: tests/CMakeFiles/sync_tests.dir/build.make
tests/sync_tests: sync_lib/libsync_matrix_lib.a
tests/sync_tests: /usr/lib/aarch64-linux-gnu/libgtest.a
tests/sync_tests: /usr/lib/aarch64-linux-gnu/libgtest_main.a
tests/sync_tests: /usr/lib/aarch64-linux-gnu/libgtest.a
tests/sync_tests: tests/CMakeFiles/sync_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/hw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sync_tests"
	cd /hw/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sync_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/sync_tests.dir/build: tests/sync_tests

.PHONY : tests/CMakeFiles/sync_tests.dir/build

tests/CMakeFiles/sync_tests.dir/clean:
	cd /hw/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/sync_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/sync_tests.dir/clean

tests/CMakeFiles/sync_tests.dir/depend:
	cd /hw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /hw /hw/tests /hw/build /hw/build/tests /hw/build/tests/CMakeFiles/sync_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/sync_tests.dir/depend

