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
include src/CMakeFiles/gmp-caching.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/gmp-caching.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/gmp-caching.dir/flags.make

src/CMakeFiles/gmp-caching.dir/caching_operations.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/caching_operations.c.o: ../src/caching_operations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/gmp-caching.dir/caching_operations.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/caching_operations.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/caching_operations.c

src/CMakeFiles/gmp-caching.dir/caching_operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/caching_operations.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/caching_operations.c > CMakeFiles/gmp-caching.dir/caching_operations.c.i

src/CMakeFiles/gmp-caching.dir/caching_operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/caching_operations.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/caching_operations.c -o CMakeFiles/gmp-caching.dir/caching_operations.c.s

src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.requires

src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.provides: src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.provides

src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/caching_operations.c.o


src/CMakeFiles/gmp-caching.dir/debug.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/debug.c.o: ../src/debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/gmp-caching.dir/debug.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/debug.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/debug.c

src/CMakeFiles/gmp-caching.dir/debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/debug.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/debug.c > CMakeFiles/gmp-caching.dir/debug.c.i

src/CMakeFiles/gmp-caching.dir/debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/debug.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/debug.c -o CMakeFiles/gmp-caching.dir/debug.c.s

src/CMakeFiles/gmp-caching.dir/debug.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/debug.c.o.requires

src/CMakeFiles/gmp-caching.dir/debug.c.o.provides: src/CMakeFiles/gmp-caching.dir/debug.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/debug.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/debug.c.o.provides

src/CMakeFiles/gmp-caching.dir/debug.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/debug.c.o


src/CMakeFiles/gmp-caching.dir/hashing.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/hashing.c.o: ../src/hashing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/gmp-caching.dir/hashing.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/hashing.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/hashing.c

src/CMakeFiles/gmp-caching.dir/hashing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/hashing.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/hashing.c > CMakeFiles/gmp-caching.dir/hashing.c.i

src/CMakeFiles/gmp-caching.dir/hashing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/hashing.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/hashing.c -o CMakeFiles/gmp-caching.dir/hashing.c.s

src/CMakeFiles/gmp-caching.dir/hashing.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/hashing.c.o.requires

src/CMakeFiles/gmp-caching.dir/hashing.c.o.provides: src/CMakeFiles/gmp-caching.dir/hashing.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/hashing.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/hashing.c.o.provides

src/CMakeFiles/gmp-caching.dir/hashing.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/hashing.c.o


src/CMakeFiles/gmp-caching.dir/hashtable.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/hashtable.c.o: ../src/hashtable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/gmp-caching.dir/hashtable.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/hashtable.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/hashtable.c

src/CMakeFiles/gmp-caching.dir/hashtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/hashtable.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/hashtable.c > CMakeFiles/gmp-caching.dir/hashtable.c.i

src/CMakeFiles/gmp-caching.dir/hashtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/hashtable.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/hashtable.c -o CMakeFiles/gmp-caching.dir/hashtable.c.s

src/CMakeFiles/gmp-caching.dir/hashtable.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/hashtable.c.o.requires

src/CMakeFiles/gmp-caching.dir/hashtable.c.o.provides: src/CMakeFiles/gmp-caching.dir/hashtable.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/hashtable.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/hashtable.c.o.provides

src/CMakeFiles/gmp-caching.dir/hashtable.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/hashtable.c.o


src/CMakeFiles/gmp-caching.dir/mastercache.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/mastercache.c.o: ../src/mastercache.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/gmp-caching.dir/mastercache.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/mastercache.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/mastercache.c

src/CMakeFiles/gmp-caching.dir/mastercache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/mastercache.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/mastercache.c > CMakeFiles/gmp-caching.dir/mastercache.c.i

src/CMakeFiles/gmp-caching.dir/mastercache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/mastercache.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/mastercache.c -o CMakeFiles/gmp-caching.dir/mastercache.c.s

src/CMakeFiles/gmp-caching.dir/mastercache.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/mastercache.c.o.requires

src/CMakeFiles/gmp-caching.dir/mastercache.c.o.provides: src/CMakeFiles/gmp-caching.dir/mastercache.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/mastercache.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/mastercache.c.o.provides

src/CMakeFiles/gmp-caching.dir/mastercache.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/mastercache.c.o


src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o: ../src/master_cache_integer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/master_cache_integer.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/master_cache_integer.c

src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/master_cache_integer.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/master_cache_integer.c > CMakeFiles/gmp-caching.dir/master_cache_integer.c.i

src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/master_cache_integer.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/master_cache_integer.c -o CMakeFiles/gmp-caching.dir/master_cache_integer.c.s

src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.requires

src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.provides: src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.provides

src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o


src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o: ../src/master_cache_rational.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/master_cache_rational.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/master_cache_rational.c

src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/master_cache_rational.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/master_cache_rational.c > CMakeFiles/gmp-caching.dir/master_cache_rational.c.i

src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/master_cache_rational.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/master_cache_rational.c -o CMakeFiles/gmp-caching.dir/master_cache_rational.c.s

src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.requires

src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.provides: src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.provides

src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o


src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o: ../src/mpz_caching.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/mpz_caching.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/mpz_caching.c

src/CMakeFiles/gmp-caching.dir/mpz_caching.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/mpz_caching.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/mpz_caching.c > CMakeFiles/gmp-caching.dir/mpz_caching.c.i

src/CMakeFiles/gmp-caching.dir/mpz_caching.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/mpz_caching.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/mpz_caching.c -o CMakeFiles/gmp-caching.dir/mpz_caching.c.s

src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.requires

src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.provides: src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.provides

src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o


src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o: src/CMakeFiles/gmp-caching.dir/flags.make
src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o: ../src/overflow_detection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gmp-caching.dir/overflow_detection.c.o   -c /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/overflow_detection.c

src/CMakeFiles/gmp-caching.dir/overflow_detection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gmp-caching.dir/overflow_detection.c.i"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/overflow_detection.c > CMakeFiles/gmp-caching.dir/overflow_detection.c.i

src/CMakeFiles/gmp-caching.dir/overflow_detection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gmp-caching.dir/overflow_detection.c.s"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/overflow_detection.c -o CMakeFiles/gmp-caching.dir/overflow_detection.c.s

src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.requires:

.PHONY : src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.requires

src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.provides: src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.requires
	$(MAKE) -f src/CMakeFiles/gmp-caching.dir/build.make src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.provides.build
.PHONY : src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.provides

src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.provides.build: src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o


# Object files for target gmp-caching
gmp__caching_OBJECTS = \
"CMakeFiles/gmp-caching.dir/caching_operations.c.o" \
"CMakeFiles/gmp-caching.dir/debug.c.o" \
"CMakeFiles/gmp-caching.dir/hashing.c.o" \
"CMakeFiles/gmp-caching.dir/hashtable.c.o" \
"CMakeFiles/gmp-caching.dir/mastercache.c.o" \
"CMakeFiles/gmp-caching.dir/master_cache_integer.c.o" \
"CMakeFiles/gmp-caching.dir/master_cache_rational.c.o" \
"CMakeFiles/gmp-caching.dir/mpz_caching.c.o" \
"CMakeFiles/gmp-caching.dir/overflow_detection.c.o"

# External object files for target gmp-caching
gmp__caching_EXTERNAL_OBJECTS =

src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/caching_operations.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/debug.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/hashing.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/hashtable.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/mastercache.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/build.make
src/libgmp-caching.a: src/CMakeFiles/gmp-caching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C static library libgmp-caching.a"
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && $(CMAKE_COMMAND) -P CMakeFiles/gmp-caching.dir/cmake_clean_target.cmake
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmp-caching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/gmp-caching.dir/build: src/libgmp-caching.a

.PHONY : src/CMakeFiles/gmp-caching.dir/build

src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/caching_operations.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/debug.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/hashing.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/hashtable.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/mastercache.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/master_cache_integer.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/master_cache_rational.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/mpz_caching.c.o.requires
src/CMakeFiles/gmp-caching.dir/requires: src/CMakeFiles/gmp-caching.dir/overflow_detection.c.o.requires

.PHONY : src/CMakeFiles/gmp-caching.dir/requires

src/CMakeFiles/gmp-caching.dir/clean:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src && $(CMAKE_COMMAND) -P CMakeFiles/gmp-caching.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/gmp-caching.dir/clean

src/CMakeFiles/gmp-caching.dir/depend:
	cd /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandra/Documents/HiWi/GMPCache/gmp-caching /home/sandra/Documents/HiWi/GMPCache/gmp-caching/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src /home/sandra/Documents/HiWi/GMPCache/gmp-caching/build/src/CMakeFiles/gmp-caching.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/gmp-caching.dir/depend
