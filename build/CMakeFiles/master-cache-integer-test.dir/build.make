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
CMAKE_SOURCE_DIR = /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build

# Include any dependencies generated for this target.
include CMakeFiles/master-cache-integer-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/master-cache-integer-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/master-cache-integer-test.dir/flags.make

CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o: CMakeFiles/master-cache-integer-test.dir/flags.make
CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o: /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c

CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c > CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.i

CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c -o CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.s

CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.requires:

.PHONY : CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.requires

CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.provides: CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.requires
	$(MAKE) -f CMakeFiles/master-cache-integer-test.dir/build.make CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.provides.build
.PHONY : CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.provides

CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.provides.build: CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o


# Object files for target master-cache-integer-test
master__cache__integer__test_OBJECTS = \
"CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o"

# External object files for target master-cache-integer-test
master__cache__integer__test_EXTERNAL_OBJECTS =

master-cache-integer-test: CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o
master-cache-integer-test: CMakeFiles/master-cache-integer-test.dir/build.make
master-cache-integer-test: libgmp-caching.a
master-cache-integer-test: CMakeFiles/master-cache-integer-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable master-cache-integer-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/master-cache-integer-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/master-cache-integer-test.dir/build: master-cache-integer-test

.PHONY : CMakeFiles/master-cache-integer-test.dir/build

CMakeFiles/master-cache-integer-test.dir/requires: CMakeFiles/master-cache-integer-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/master-cache-integer-test.c.o.requires

.PHONY : CMakeFiles/master-cache-integer-test.dir/requires

CMakeFiles/master-cache-integer-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/master-cache-integer-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/master-cache-integer-test.dir/clean

CMakeFiles/master-cache-integer-test.dir/depend:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles/master-cache-integer-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/master-cache-integer-test.dir/depend

