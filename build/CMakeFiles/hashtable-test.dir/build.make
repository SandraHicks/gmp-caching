# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/sandra/Documents/HiWi/GMPCache/gmp-caching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build

# Include any dependencies generated for this target.
include CMakeFiles/hashtable-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hashtable-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hashtable-test.dir/flags.make

CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o: CMakeFiles/hashtable-test.dir/flags.make
CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o: ../Tests/hashtable-test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/hashtable-test.c

CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/hashtable-test.c > CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.i

CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/hashtable-test.c -o CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.s

CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.requires:

.PHONY : CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.requires

CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.provides: CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.requires
	$(MAKE) -f CMakeFiles/hashtable-test.dir/build.make CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.provides.build
.PHONY : CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.provides

CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.provides.build: CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o


# Object files for target hashtable-test
hashtable__test_OBJECTS = \
"CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o"

# External object files for target hashtable-test
hashtable__test_EXTERNAL_OBJECTS =

hashtable-test: CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o
hashtable-test: CMakeFiles/hashtable-test.dir/build.make
hashtable-test: libgmp-caching.a
hashtable-test: CMakeFiles/hashtable-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hashtable-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hashtable-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hashtable-test.dir/build: hashtable-test

.PHONY : CMakeFiles/hashtable-test.dir/build

CMakeFiles/hashtable-test.dir/requires: CMakeFiles/hashtable-test.dir/Tests/hashtable-test.c.o.requires

.PHONY : CMakeFiles/hashtable-test.dir/requires

CMakeFiles/hashtable-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hashtable-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hashtable-test.dir/clean

CMakeFiles/hashtable-test.dir/depend:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles/hashtable-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hashtable-test.dir/depend

