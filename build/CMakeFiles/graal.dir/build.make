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
CMAKE_SOURCE_DIR = /home/bergony/lp_lista_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bergony/lp_lista_2/build

# Include any dependencies generated for this target.
include CMakeFiles/graal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graal.dir/flags.make

CMakeFiles/graal.dir/src/graal.cpp.o: CMakeFiles/graal.dir/flags.make
CMakeFiles/graal.dir/src/graal.cpp.o: ../src/graal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bergony/lp_lista_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graal.dir/src/graal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graal.dir/src/graal.cpp.o -c /home/bergony/lp_lista_2/src/graal.cpp

CMakeFiles/graal.dir/src/graal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graal.dir/src/graal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bergony/lp_lista_2/src/graal.cpp > CMakeFiles/graal.dir/src/graal.cpp.i

CMakeFiles/graal.dir/src/graal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graal.dir/src/graal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bergony/lp_lista_2/src/graal.cpp -o CMakeFiles/graal.dir/src/graal.cpp.s

CMakeFiles/graal.dir/src/graal.cpp.o.requires:

.PHONY : CMakeFiles/graal.dir/src/graal.cpp.o.requires

CMakeFiles/graal.dir/src/graal.cpp.o.provides: CMakeFiles/graal.dir/src/graal.cpp.o.requires
	$(MAKE) -f CMakeFiles/graal.dir/build.make CMakeFiles/graal.dir/src/graal.cpp.o.provides.build
.PHONY : CMakeFiles/graal.dir/src/graal.cpp.o.provides

CMakeFiles/graal.dir/src/graal.cpp.o.provides.build: CMakeFiles/graal.dir/src/graal.cpp.o


# Object files for target graal
graal_OBJECTS = \
"CMakeFiles/graal.dir/src/graal.cpp.o"

# External object files for target graal
graal_EXTERNAL_OBJECTS =

libgraal.a: CMakeFiles/graal.dir/src/graal.cpp.o
libgraal.a: CMakeFiles/graal.dir/build.make
libgraal.a: CMakeFiles/graal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bergony/lp_lista_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgraal.a"
	$(CMAKE_COMMAND) -P CMakeFiles/graal.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graal.dir/build: libgraal.a

.PHONY : CMakeFiles/graal.dir/build

CMakeFiles/graal.dir/requires: CMakeFiles/graal.dir/src/graal.cpp.o.requires

.PHONY : CMakeFiles/graal.dir/requires

CMakeFiles/graal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graal.dir/clean

CMakeFiles/graal.dir/depend:
	cd /home/bergony/lp_lista_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bergony/lp_lista_2 /home/bergony/lp_lista_2 /home/bergony/lp_lista_2/build /home/bergony/lp_lista_2/build /home/bergony/lp_lista_2/build/CMakeFiles/graal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graal.dir/depend

