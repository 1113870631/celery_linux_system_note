# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ww/celery_linux_system_note/socket/TCP/clint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ww/celery_linux_system_note/socket/TCP/clint/build

# Include any dependencies generated for this target.
include CMakeFiles/TCP_CLINT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TCP_CLINT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TCP_CLINT.dir/flags.make

CMakeFiles/TCP_CLINT.dir/main.c.o: CMakeFiles/TCP_CLINT.dir/flags.make
CMakeFiles/TCP_CLINT.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ww/celery_linux_system_note/socket/TCP/clint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TCP_CLINT.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TCP_CLINT.dir/main.c.o   -c /home/ww/celery_linux_system_note/socket/TCP/clint/main.c

CMakeFiles/TCP_CLINT.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TCP_CLINT.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ww/celery_linux_system_note/socket/TCP/clint/main.c > CMakeFiles/TCP_CLINT.dir/main.c.i

CMakeFiles/TCP_CLINT.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TCP_CLINT.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ww/celery_linux_system_note/socket/TCP/clint/main.c -o CMakeFiles/TCP_CLINT.dir/main.c.s

CMakeFiles/TCP_CLINT.dir/main.c.o.requires:

.PHONY : CMakeFiles/TCP_CLINT.dir/main.c.o.requires

CMakeFiles/TCP_CLINT.dir/main.c.o.provides: CMakeFiles/TCP_CLINT.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/TCP_CLINT.dir/build.make CMakeFiles/TCP_CLINT.dir/main.c.o.provides.build
.PHONY : CMakeFiles/TCP_CLINT.dir/main.c.o.provides

CMakeFiles/TCP_CLINT.dir/main.c.o.provides.build: CMakeFiles/TCP_CLINT.dir/main.c.o


# Object files for target TCP_CLINT
TCP_CLINT_OBJECTS = \
"CMakeFiles/TCP_CLINT.dir/main.c.o"

# External object files for target TCP_CLINT
TCP_CLINT_EXTERNAL_OBJECTS =

TCP_CLINT: CMakeFiles/TCP_CLINT.dir/main.c.o
TCP_CLINT: CMakeFiles/TCP_CLINT.dir/build.make
TCP_CLINT: CMakeFiles/TCP_CLINT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ww/celery_linux_system_note/socket/TCP/clint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TCP_CLINT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TCP_CLINT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TCP_CLINT.dir/build: TCP_CLINT

.PHONY : CMakeFiles/TCP_CLINT.dir/build

CMakeFiles/TCP_CLINT.dir/requires: CMakeFiles/TCP_CLINT.dir/main.c.o.requires

.PHONY : CMakeFiles/TCP_CLINT.dir/requires

CMakeFiles/TCP_CLINT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TCP_CLINT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TCP_CLINT.dir/clean

CMakeFiles/TCP_CLINT.dir/depend:
	cd /home/ww/celery_linux_system_note/socket/TCP/clint/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ww/celery_linux_system_note/socket/TCP/clint /home/ww/celery_linux_system_note/socket/TCP/clint /home/ww/celery_linux_system_note/socket/TCP/clint/build /home/ww/celery_linux_system_note/socket/TCP/clint/build /home/ww/celery_linux_system_note/socket/TCP/clint/build/CMakeFiles/TCP_CLINT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TCP_CLINT.dir/depend

