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

# Utility rule file for ALL.

# Include the progress variables for this target.
include CMakeFiles/ALL.dir/progress.make

CMakeFiles/ALL:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating API documentation with Doxygen"
	/usr/bin/doxygen /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/Doxyfile

ALL: CMakeFiles/ALL
ALL: CMakeFiles/ALL.dir/build.make

.PHONY : ALL

# Rule to build all files generated by this target.
CMakeFiles/ALL.dir/build: ALL

.PHONY : CMakeFiles/ALL.dir/build

CMakeFiles/ALL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ALL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ALL.dir/clean

CMakeFiles/ALL.dir/depend:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching/CMakeFiles/ALL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ALL.dir/depend

