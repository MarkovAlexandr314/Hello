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
CMAKE_SOURCE_DIR = "C:\Users\User\Desktop\projects\Class vector"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Desktop\projects\Class vector\build"

# Include any dependencies generated for this target.
include CMakeFiles/vector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vector.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector.dir/flags.make

CMakeFiles/vector.dir/main.cpp.obj: CMakeFiles/vector.dir/flags.make
CMakeFiles/vector.dir/main.cpp.obj: C:/Users/User/Desktop/projects/Class\ vector/main.cpp
CMakeFiles/vector.dir/main.cpp.obj: CMakeFiles/vector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\User\Desktop\projects\Class vector\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vector.dir/main.cpp.obj -MF CMakeFiles\vector.dir\main.cpp.obj.d -o CMakeFiles\vector.dir\main.cpp.obj -c "C:\Users\User\Desktop\projects\Class vector\main.cpp"

CMakeFiles/vector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/vector.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\projects\Class vector\main.cpp" > CMakeFiles\vector.dir\main.cpp.i

CMakeFiles/vector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/vector.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\projects\Class vector\main.cpp" -o CMakeFiles\vector.dir\main.cpp.s

CMakeFiles/vector.dir/vector.cpp.obj: CMakeFiles/vector.dir/flags.make
CMakeFiles/vector.dir/vector.cpp.obj: C:/Users/User/Desktop/projects/Class\ vector/vector.cpp
CMakeFiles/vector.dir/vector.cpp.obj: CMakeFiles/vector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\User\Desktop\projects\Class vector\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vector.dir/vector.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vector.dir/vector.cpp.obj -MF CMakeFiles\vector.dir\vector.cpp.obj.d -o CMakeFiles\vector.dir\vector.cpp.obj -c "C:\Users\User\Desktop\projects\Class vector\vector.cpp"

CMakeFiles/vector.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/vector.dir/vector.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\projects\Class vector\vector.cpp" > CMakeFiles\vector.dir\vector.cpp.i

CMakeFiles/vector.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/vector.dir/vector.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\projects\Class vector\vector.cpp" -o CMakeFiles\vector.dir\vector.cpp.s

# Object files for target vector
vector_OBJECTS = \
"CMakeFiles/vector.dir/main.cpp.obj" \
"CMakeFiles/vector.dir/vector.cpp.obj"

# External object files for target vector
vector_EXTERNAL_OBJECTS =

vector.exe: CMakeFiles/vector.dir/main.cpp.obj
vector.exe: CMakeFiles/vector.dir/vector.cpp.obj
vector.exe: CMakeFiles/vector.dir/build.make
vector.exe: CMakeFiles/vector.dir/linkLibs.rsp
vector.exe: CMakeFiles/vector.dir/objects1.rsp
vector.exe: CMakeFiles/vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\User\Desktop\projects\Class vector\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable vector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\vector.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector.dir/build: vector.exe
.PHONY : CMakeFiles/vector.dir/build

CMakeFiles/vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\vector.dir\cmake_clean.cmake
.PHONY : CMakeFiles/vector.dir/clean

CMakeFiles/vector.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Desktop\projects\Class vector" "C:\Users\User\Desktop\projects\Class vector" "C:\Users\User\Desktop\projects\Class vector\build" "C:\Users\User\Desktop\projects\Class vector\build" "C:\Users\User\Desktop\projects\Class vector\build\CMakeFiles\vector.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/vector.dir/depend
