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
include CMakeFiles/if_else.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/if_else.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/if_else.dir/flags.make

CMakeFiles/if_else.dir/if_else.cpp.obj: CMakeFiles/if_else.dir/flags.make
CMakeFiles/if_else.dir/if_else.cpp.obj: ../if_else.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/if_else.dir/if_else.cpp.obj"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\if_else.dir\if_else.cpp.obj -c D:\Data_Structure_Codes\C_Language_Retest\if_else.cpp

CMakeFiles/if_else.dir/if_else.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/if_else.dir/if_else.cpp.i"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Data_Structure_Codes\C_Language_Retest\if_else.cpp > CMakeFiles\if_else.dir\if_else.cpp.i

CMakeFiles/if_else.dir/if_else.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/if_else.dir/if_else.cpp.s"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Data_Structure_Codes\C_Language_Retest\if_else.cpp -o CMakeFiles\if_else.dir\if_else.cpp.s

# Object files for target if_else
if_else_OBJECTS = \
"CMakeFiles/if_else.dir/if_else.cpp.obj"

# External object files for target if_else
if_else_EXTERNAL_OBJECTS =

if_else.exe: CMakeFiles/if_else.dir/if_else.cpp.obj
if_else.exe: CMakeFiles/if_else.dir/build.make
if_else.exe: CMakeFiles/if_else.dir/linklibs.rsp
if_else.exe: CMakeFiles/if_else.dir/objects1.rsp
if_else.exe: CMakeFiles/if_else.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable if_else.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\if_else.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/if_else.dir/build: if_else.exe

.PHONY : CMakeFiles/if_else.dir/build

CMakeFiles/if_else.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\if_else.dir\cmake_clean.cmake
.PHONY : CMakeFiles/if_else.dir/clean

CMakeFiles/if_else.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Data_Structure_Codes\C_Language_Retest D:\Data_Structure_Codes\C_Language_Retest D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug D:\Data_Structure_Codes\C_Language_Retest\cmake-build-debug\CMakeFiles\if_else.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/if_else.dir/depend

