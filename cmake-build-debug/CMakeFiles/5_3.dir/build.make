# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\NewFile\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\NewFile\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Data_Structure_Codes\C_Language_Retest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/5_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5_3.dir/flags.make

CMakeFiles/5_3.dir/5_3.cpp.obj: CMakeFiles/5_3.dir/flags.make
CMakeFiles/5_3.dir/5_3.cpp.obj: ../5_3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/5_3.dir/5_3.cpp.obj"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\5_3.dir\5_3.cpp.obj -c D:\Data_Structure_Codes\C_Language_Retest\5_3.cpp

CMakeFiles/5_3.dir/5_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5_3.dir/5_3.cpp.i"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Data_Structure_Codes\C_Language_Retest\5_3.cpp > CMakeFiles\5_3.dir\5_3.cpp.i

CMakeFiles/5_3.dir/5_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5_3.dir/5_3.cpp.s"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Data_Structure_Codes\C_Language_Retest\5_3.cpp -o CMakeFiles\5_3.dir\5_3.cpp.s

# Object files for target 5_3
5_3_OBJECTS = \
"CMakeFiles/5_3.dir/5_3.cpp.obj"

# External object files for target 5_3
5_3_EXTERNAL_OBJECTS =

5_3.exe: CMakeFiles/5_3.dir/5_3.cpp.obj
5_3.exe: CMakeFiles/5_3.dir/build.make
5_3.exe: CMakeFiles/5_3.dir/linklibs.rsp
5_3.exe: CMakeFiles/5_3.dir/objects1.rsp
5_3.exe: CMakeFiles/5_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5_3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\5_3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5_3.dir/build: 5_3.exe

.PHONY : CMakeFiles/5_3.dir/build

CMakeFiles/5_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\5_3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/5_3.dir/clean

CMakeFiles/5_3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Data_Structure_Codes\C_Language_Retest D:\Data_Structure_Codes\C_Language_Retest D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug\CMakeFiles\5_3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5_3.dir/depend
