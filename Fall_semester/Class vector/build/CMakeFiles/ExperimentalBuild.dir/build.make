# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\cmake-3.27.6-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-3.27.6-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\Desktop\projects\Fall_semester\Class vector"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Desktop\projects\Fall_semester\Class vector\build"

# Utility rule file for ExperimentalBuild.

# Include any custom commands dependencies for this target.
include CMakeFiles/ExperimentalBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ExperimentalBuild.dir/progress.make

CMakeFiles/ExperimentalBuild:
	C:\cmake-3.27.6-windows-x86_64\bin\ctest.exe -D ExperimentalBuild

ExperimentalBuild: CMakeFiles/ExperimentalBuild
ExperimentalBuild: CMakeFiles/ExperimentalBuild.dir/build.make
.PHONY : ExperimentalBuild

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalBuild.dir/build: ExperimentalBuild
.PHONY : CMakeFiles/ExperimentalBuild.dir/build

CMakeFiles/ExperimentalBuild.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExperimentalBuild.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalBuild.dir/clean

CMakeFiles/ExperimentalBuild.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Desktop\projects\Fall_semester\Class vector" "C:\Users\User\Desktop\projects\Fall_semester\Class vector" "C:\Users\User\Desktop\projects\Fall_semester\Class vector\build" "C:\Users\User\Desktop\projects\Fall_semester\Class vector\build" "C:\Users\User\Desktop\projects\Fall_semester\Class vector\build\CMakeFiles\ExperimentalBuild.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/ExperimentalBuild.dir/depend

