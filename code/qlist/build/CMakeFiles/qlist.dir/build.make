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
CMAKE_SOURCE_DIR = /home/ww/celery_linux_system_note/code/qlist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ww/celery_linux_system_note/code/qlist/build

# Include any dependencies generated for this target.
include CMakeFiles/qlist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qlist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qlist.dir/flags.make

CMakeFiles/qlist.dir/main.c.o: CMakeFiles/qlist.dir/flags.make
CMakeFiles/qlist.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ww/celery_linux_system_note/code/qlist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/qlist.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/qlist.dir/main.c.o   -c /home/ww/celery_linux_system_note/code/qlist/main.c

CMakeFiles/qlist.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/qlist.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ww/celery_linux_system_note/code/qlist/main.c > CMakeFiles/qlist.dir/main.c.i

CMakeFiles/qlist.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/qlist.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ww/celery_linux_system_note/code/qlist/main.c -o CMakeFiles/qlist.dir/main.c.s

CMakeFiles/qlist.dir/main.c.o.requires:

.PHONY : CMakeFiles/qlist.dir/main.c.o.requires

CMakeFiles/qlist.dir/main.c.o.provides: CMakeFiles/qlist.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/qlist.dir/build.make CMakeFiles/qlist.dir/main.c.o.provides.build
.PHONY : CMakeFiles/qlist.dir/main.c.o.provides

CMakeFiles/qlist.dir/main.c.o.provides.build: CMakeFiles/qlist.dir/main.c.o


CMakeFiles/qlist.dir/qlist.c.o: CMakeFiles/qlist.dir/flags.make
CMakeFiles/qlist.dir/qlist.c.o: ../qlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ww/celery_linux_system_note/code/qlist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/qlist.dir/qlist.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/qlist.dir/qlist.c.o   -c /home/ww/celery_linux_system_note/code/qlist/qlist.c

CMakeFiles/qlist.dir/qlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/qlist.dir/qlist.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ww/celery_linux_system_note/code/qlist/qlist.c > CMakeFiles/qlist.dir/qlist.c.i

CMakeFiles/qlist.dir/qlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/qlist.dir/qlist.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ww/celery_linux_system_note/code/qlist/qlist.c -o CMakeFiles/qlist.dir/qlist.c.s

CMakeFiles/qlist.dir/qlist.c.o.requires:

.PHONY : CMakeFiles/qlist.dir/qlist.c.o.requires

CMakeFiles/qlist.dir/qlist.c.o.provides: CMakeFiles/qlist.dir/qlist.c.o.requires
	$(MAKE) -f CMakeFiles/qlist.dir/build.make CMakeFiles/qlist.dir/qlist.c.o.provides.build
.PHONY : CMakeFiles/qlist.dir/qlist.c.o.provides

CMakeFiles/qlist.dir/qlist.c.o.provides.build: CMakeFiles/qlist.dir/qlist.c.o


# Object files for target qlist
qlist_OBJECTS = \
"CMakeFiles/qlist.dir/main.c.o" \
"CMakeFiles/qlist.dir/qlist.c.o"

# External object files for target qlist
qlist_EXTERNAL_OBJECTS =

qlist: CMakeFiles/qlist.dir/main.c.o
qlist: CMakeFiles/qlist.dir/qlist.c.o
qlist: CMakeFiles/qlist.dir/build.make
qlist: CMakeFiles/qlist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ww/celery_linux_system_note/code/qlist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable qlist"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qlist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qlist.dir/build: qlist

.PHONY : CMakeFiles/qlist.dir/build

CMakeFiles/qlist.dir/requires: CMakeFiles/qlist.dir/main.c.o.requires
CMakeFiles/qlist.dir/requires: CMakeFiles/qlist.dir/qlist.c.o.requires

.PHONY : CMakeFiles/qlist.dir/requires

CMakeFiles/qlist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qlist.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qlist.dir/clean

CMakeFiles/qlist.dir/depend:
	cd /home/ww/celery_linux_system_note/code/qlist/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ww/celery_linux_system_note/code/qlist /home/ww/celery_linux_system_note/code/qlist /home/ww/celery_linux_system_note/code/qlist/build /home/ww/celery_linux_system_note/code/qlist/build /home/ww/celery_linux_system_note/code/qlist/build/CMakeFiles/qlist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qlist.dir/depend

