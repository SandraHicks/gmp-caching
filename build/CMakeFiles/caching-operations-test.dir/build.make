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
include CMakeFiles/caching-operations-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/caching-operations-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/caching-operations-test.dir/flags.make

CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o: CMakeFiles/caching-operations-test.dir/flags.make
CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o: /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c

CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c > CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.i

CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c -o CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.s

CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.requires:

.PHONY : CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.requires

CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.provides: CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.requires
	$(MAKE) -f CMakeFiles/caching-operations-test.dir/build.make CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.provides.build
.PHONY : CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.provides

CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.provides.build: CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o


# Object files for target caching-operations-test
caching__operations__test_OBJECTS = \
"CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o"

# External object files for target caching-operations-test
caching__operations__test_EXTERNAL_OBJECTS =

caching-operations-test: CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o
caching-operations-test: CMakeFiles/caching-operations-test.dir/build.make
caching-operations-test: libgmp-caching.a
caching-operations-test: CMakeFiles/caching-operations-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable caching-operations-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/caching-operations-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/caching-operations-test.dir/build: caching-operations-test

.PHONY : CMakeFiles/caching-operations-test.dir/build

CMakeFiles/caching-operations-test.dir/requires: CMakeFiles/caching-operations-test.dir/home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test.c.o.requires

.PHONY : CMakeFiles/caching-operations-test.dir/requires

CMakeFiles/caching-operations-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/caching-operations-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/caching-operations-test.dir/clean

CMakeFiles/caching-operations-test.dir/depend:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles/caching-operations-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/caching-operations-test.dir/depend

