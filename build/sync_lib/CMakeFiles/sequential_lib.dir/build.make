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
include sync_lib/CMakeFiles/sequential_lib.dir/depend.make

# Include the progress variables for this target.
include sync_lib/CMakeFiles/sequential_lib.dir/progress.make

# Include the compile flags for this target's objects.
include sync_lib/CMakeFiles/sequential_lib.dir/flags.make

sync_lib/CMakeFiles/sequential_lib.dir/main.c.o: sync_lib/CMakeFiles/sequential_lib.dir/flags.make
sync_lib/CMakeFiles/sequential_lib.dir/main.c.o: ../sync_lib/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/hw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sync_lib/CMakeFiles/sequential_lib.dir/main.c.o"
	cd /hw/build/sync_lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sequential_lib.dir/main.c.o -c /hw/sync_lib/main.c

sync_lib/CMakeFiles/sequential_lib.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sequential_lib.dir/main.c.i"
	cd /hw/build/sync_lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /hw/sync_lib/main.c > CMakeFiles/sequential_lib.dir/main.c.i

sync_lib/CMakeFiles/sequential_lib.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sequential_lib.dir/main.c.s"
	cd /hw/build/sync_lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /hw/sync_lib/main.c -o CMakeFiles/sequential_lib.dir/main.c.s

# Object files for target sequential_lib
sequential_lib_OBJECTS = \
"CMakeFiles/sequential_lib.dir/main.c.o"

# External object files for target sequential_lib
sequential_lib_EXTERNAL_OBJECTS =

sync_lib/sequential_lib: sync_lib/CMakeFiles/sequential_lib.dir/main.c.o
sync_lib/sequential_lib: sync_lib/CMakeFiles/sequential_lib.dir/build.make
sync_lib/sequential_lib: sync_lib/libsync_matrix_lib.a
sync_lib/sequential_lib: sync_lib/CMakeFiles/sequential_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/hw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sequential_lib"
	cd /hw/build/sync_lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sequential_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sync_lib/CMakeFiles/sequential_lib.dir/build: sync_lib/sequential_lib

.PHONY : sync_lib/CMakeFiles/sequential_lib.dir/build

sync_lib/CMakeFiles/sequential_lib.dir/clean:
	cd /hw/build/sync_lib && $(CMAKE_COMMAND) -P CMakeFiles/sequential_lib.dir/cmake_clean.cmake
.PHONY : sync_lib/CMakeFiles/sequential_lib.dir/clean

sync_lib/CMakeFiles/sequential_lib.dir/depend:
	cd /hw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /hw /hw/sync_lib /hw/build /hw/build/sync_lib /hw/build/sync_lib/CMakeFiles/sequential_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sync_lib/CMakeFiles/sequential_lib.dir/depend

