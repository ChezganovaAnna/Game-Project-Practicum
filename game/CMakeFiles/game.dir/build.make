# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = C:\Users\Public\Documents\ProjectPracticum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Public\Documents\ProjectPracticum

# Include any dependencies generated for this target.
include game/CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include game/CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include game/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include game/CMakeFiles/game.dir/flags.make

game/CMakeFiles/game.dir/main.cpp.obj: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/main.cpp.obj: game/CMakeFiles/game.dir/includes_CXX.rsp
game/CMakeFiles/game.dir/main.cpp.obj: game/main.cpp
game/CMakeFiles/game.dir/main.cpp.obj: game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Public\Documents\ProjectPracticum\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object game/CMakeFiles/game.dir/main.cpp.obj"
	cd /d C:\Users\Public\Documents\ProjectPracticum\game && C:\Users\tchez\Downloads\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT game/CMakeFiles/game.dir/main.cpp.obj -MF CMakeFiles\game.dir\main.cpp.obj.d -o CMakeFiles\game.dir\main.cpp.obj -c C:\Users\Public\Documents\ProjectPracticum\game\main.cpp

game/CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	cd /d C:\Users\Public\Documents\ProjectPracticum\game && C:\Users\tchez\Downloads\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Public\Documents\ProjectPracticum\game\main.cpp > CMakeFiles\game.dir\main.cpp.i

game/CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	cd /d C:\Users\Public\Documents\ProjectPracticum\game && C:\Users\tchez\Downloads\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Public\Documents\ProjectPracticum\game\main.cpp -o CMakeFiles\game.dir\main.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main.cpp.obj"

# External object files for target game
game_EXTERNAL_OBJECTS =

game/game.exe: game/CMakeFiles/game.dir/main.cpp.obj
game/game.exe: game/CMakeFiles/game.dir/build.make
game/game.exe: game/CMakeFiles/game.dir/linkLibs.rsp
game/game.exe: game/CMakeFiles/game.dir/objects1.rsp
game/game.exe: game/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Public\Documents\ProjectPracticum\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game.exe"
	cd /d C:\Users\Public\Documents\ProjectPracticum\game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
game/CMakeFiles/game.dir/build: game/game.exe
.PHONY : game/CMakeFiles/game.dir/build

game/CMakeFiles/game.dir/clean:
	cd /d C:\Users\Public\Documents\ProjectPracticum\game && $(CMAKE_COMMAND) -P CMakeFiles\game.dir\cmake_clean.cmake
.PHONY : game/CMakeFiles/game.dir/clean

game/CMakeFiles/game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Public\Documents\ProjectPracticum C:\Users\Public\Documents\ProjectPracticum\game C:\Users\Public\Documents\ProjectPracticum C:\Users\Public\Documents\ProjectPracticum\game C:\Users\Public\Documents\ProjectPracticum\game\CMakeFiles\game.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : game/CMakeFiles/game.dir/depend

