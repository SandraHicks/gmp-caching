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
CMAKE_BINARY_DIR = /home/sandra/Documents/HiWi/GMPCache/gmp-caching

# Include any dependencies generated for this target.
include CMakeFiles/hash-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hash-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hash-test.dir/flags.make

CMakeFiles/hash-test.dir/Tests/hash-test.c.o: CMakeFiles/hash-test.dir/flags.make
CMakeFiles/hash-test.dir/Tests/hash-test.c.o: Tests/hash-test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hash-test.dir/Tests/hash-test.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hash-test.dir/Tests/hash-test.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/hash-test.c

CMakeFiles/hash-test.dir/Tests/hash-test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hash-test.dir/Tests/hash-test.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/hash-test.c > CMakeFiles/hash-test.dir/Tests/hash-test.c.i

CMakeFiles/hash-test.dir/Tests/hash-test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hash-test.dir/Tests/hash-test.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/hash-test.c -o CMakeFiles/hash-test.dir/Tests/hash-test.c.s

CMakeFiles/hash-test.dir/Tests/hash-test.c.o.requires:

.PHONY : CMakeFiles/hash-test.dir/Tests/hash-test.c.o.requires

CMakeFiles/hash-test.dir/Tests/hash-test.c.o.provides: CMakeFiles/hash-test.dir/Tests/hash-test.c.o.requires
	$(MAKE) -f CMakeFiles/hash-test.dir/build.make CMakeFiles/hash-test.dir/Tests/hash-test.c.o.provides.build
.PHONY : CMakeFiles/hash-test.dir/Tests/hash-test.c.o.provides

CMakeFiles/hash-test.dir/Tests/hash-test.c.o.provides.build: CMakeFiles/hash-test.dir/Tests/hash-test.c.o


# Object files for target hash-test
hash__test_OBJECTS = \
"CMakeFiles/hash-test.dir/Tests/hash-test.c.o"

# External object files for target hash-test
hash__test_EXTERNAL_OBJECTS =

hash-test: CMakeFiles/hash-test.dir/Tests/hash-test.c.o
hash-test: CMakeFiles/hash-test.dir/build.make
hash-test: libgmp-caching.a
hash-test: CMakeFiles/hash-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hash-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hash-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hash-test.dir/build: hash-test

.PHONY : CMakeFiles/hash-test.dir/build

CMakeFiles/hash-test.dir/requires: CMakeFiles/hash-test.dir/Tests/hash-test.c.o.requires

.PHONY : CMakeFiles/hash-test.dir/requires

CMakeFiles/hash-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hash-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hash-test.dir/clean

CMakeFiles/hash-test.dir/depend:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching/CMakeFiles/hash-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hash-test.dir/depend

