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
include src/CMakeFiles/caching-operations-test-advanced.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/caching-operations-test-advanced.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/caching-operations-test-advanced.dir/flags.make

src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o: src/CMakeFiles/caching-operations-test-advanced.dir/flags.make
src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o: ../Tests/caching-operations-test-advanced.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test-advanced.c

src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test-advanced.c > CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.i

src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/Tests/caching-operations-test-advanced.c -o CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.s

src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.requires:

.PHONY : src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.requires

src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.provides: src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.requires
	$(MAKE) -f src/CMakeFiles/caching-operations-test-advanced.dir/build.make src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.provides.build
.PHONY : src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.provides

src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.provides.build: src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o


# Object files for target caching-operations-test-advanced
caching__operations__test__advanced_OBJECTS = \
"CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o"

# External object files for target caching-operations-test-advanced
caching__operations__test__advanced_EXTERNAL_OBJECTS =

src/caching-operations-test-advanced: src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o
src/caching-operations-test-advanced: src/CMakeFiles/caching-operations-test-advanced.dir/build.make
src/caching-operations-test-advanced: src/libgmp-caching.a
src/caching-operations-test-advanced: src/CMakeFiles/caching-operations-test-advanced.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable caching-operations-test-advanced"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/caching-operations-test-advanced.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/caching-operations-test-advanced.dir/build: src/caching-operations-test-advanced

.PHONY : src/CMakeFiles/caching-operations-test-advanced.dir/build

src/CMakeFiles/caching-operations-test-advanced.dir/requires: src/CMakeFiles/caching-operations-test-advanced.dir/__/Tests/caching-operations-test-advanced.c.o.requires

.PHONY : src/CMakeFiles/caching-operations-test-advanced.dir/requires

src/CMakeFiles/caching-operations-test-advanced.dir/clean:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && $(CMAKE_COMMAND) -P CMakeFiles/caching-operations-test-advanced.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/caching-operations-test-advanced.dir/clean

src/CMakeFiles/caching-operations-test-advanced.dir/depend:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src/CMakeFiles/caching-operations-test-advanced.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/caching-operations-test-advanced.dir/depend

