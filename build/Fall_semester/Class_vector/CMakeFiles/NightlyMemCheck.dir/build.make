# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Desktop\projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Desktop\projects\build

# Utility rule file for NightlyMemCheck.

# Include any custom commands dependencies for this target.
include Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/compiler_depend.make

# Include the progress variables for this target.
include Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/progress.make

Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck:
	cd /d C:\Users\User\Desktop\projects\build\Fall_semester\Class_vector && "C:\Program Files\CMake\bin\ctest.exe" -D NightlyMemCheck

NightlyMemCheck: Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck
NightlyMemCheck: Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/build.make
.PHONY : NightlyMemCheck

# Rule to build all files generated by this target.
Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/build: NightlyMemCheck
.PHONY : Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/build

Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/clean:
	cd /d C:\Users\User\Desktop\projects\build\Fall_semester\Class_vector && $(CMAKE_COMMAND) -P CMakeFiles\NightlyMemCheck.dir\cmake_clean.cmake
.PHONY : Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/clean

Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Desktop\projects C:\Users\User\Desktop\projects\Fall_semester\Class_vector C:\Users\User\Desktop\projects\build C:\Users\User\Desktop\projects\build\Fall_semester\Class_vector C:\Users\User\Desktop\projects\build\Fall_semester\Class_vector\CMakeFiles\NightlyMemCheck.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : Fall_semester/Class_vector/CMakeFiles/NightlyMemCheck.dir/depend

