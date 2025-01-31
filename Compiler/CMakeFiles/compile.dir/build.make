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
CMAKE_SOURCE_DIR = /home/chill/Documents/workspace/cs5300/Final_Project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chill/Documents/workspace/cs5300/Final_Project/Compiler

# Include any dependencies generated for this target.
include CMakeFiles/compile.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/compile.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/compile.dir/flags.make

parser.cpp: /home/chill/Documents/workspace/cs5300/Final_Project/src/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][Parser] Building parser with bison 3.0.4"
	cd /home/chill/Documents/workspace/cs5300/Final_Project/src && /usr/bin/bison -d -o /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp parser.y

parser.hpp: parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate parser.hpp

scanner.cpp: /home/chill/Documents/workspace/cs5300/Final_Project/src/scanner.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][Scanner] Building scanner with flex 2.6.4"
	cd /home/chill/Documents/workspace/cs5300/Final_Project/src && /usr/bin/flex -o/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/scanner.cpp scanner.l

CMakeFiles/compile.dir/main.cpp.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/main.cpp.o: /home/chill/Documents/workspace/cs5300/Final_Project/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/compile.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile.dir/main.cpp.o -c /home/chill/Documents/workspace/cs5300/Final_Project/src/main.cpp

CMakeFiles/compile.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chill/Documents/workspace/cs5300/Final_Project/src/main.cpp > CMakeFiles/compile.dir/main.cpp.i

CMakeFiles/compile.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chill/Documents/workspace/cs5300/Final_Project/src/main.cpp -o CMakeFiles/compile.dir/main.cpp.s

CMakeFiles/compile.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/compile.dir/main.cpp.o.requires

CMakeFiles/compile.dir/main.cpp.o.provides: CMakeFiles/compile.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/compile.dir/build.make CMakeFiles/compile.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/compile.dir/main.cpp.o.provides

CMakeFiles/compile.dir/main.cpp.o.provides.build: CMakeFiles/compile.dir/main.cpp.o


CMakeFiles/compile.dir/RegisterPool.cpp.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/RegisterPool.cpp.o: /home/chill/Documents/workspace/cs5300/Final_Project/src/RegisterPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/compile.dir/RegisterPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile.dir/RegisterPool.cpp.o -c /home/chill/Documents/workspace/cs5300/Final_Project/src/RegisterPool.cpp

CMakeFiles/compile.dir/RegisterPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile.dir/RegisterPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chill/Documents/workspace/cs5300/Final_Project/src/RegisterPool.cpp > CMakeFiles/compile.dir/RegisterPool.cpp.i

CMakeFiles/compile.dir/RegisterPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile.dir/RegisterPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chill/Documents/workspace/cs5300/Final_Project/src/RegisterPool.cpp -o CMakeFiles/compile.dir/RegisterPool.cpp.s

CMakeFiles/compile.dir/RegisterPool.cpp.o.requires:

.PHONY : CMakeFiles/compile.dir/RegisterPool.cpp.o.requires

CMakeFiles/compile.dir/RegisterPool.cpp.o.provides: CMakeFiles/compile.dir/RegisterPool.cpp.o.requires
	$(MAKE) -f CMakeFiles/compile.dir/build.make CMakeFiles/compile.dir/RegisterPool.cpp.o.provides.build
.PHONY : CMakeFiles/compile.dir/RegisterPool.cpp.o.provides

CMakeFiles/compile.dir/RegisterPool.cpp.o.provides.build: CMakeFiles/compile.dir/RegisterPool.cpp.o


CMakeFiles/compile.dir/symbol_table.cpp.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/symbol_table.cpp.o: /home/chill/Documents/workspace/cs5300/Final_Project/src/symbol_table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/compile.dir/symbol_table.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile.dir/symbol_table.cpp.o -c /home/chill/Documents/workspace/cs5300/Final_Project/src/symbol_table.cpp

CMakeFiles/compile.dir/symbol_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile.dir/symbol_table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chill/Documents/workspace/cs5300/Final_Project/src/symbol_table.cpp > CMakeFiles/compile.dir/symbol_table.cpp.i

CMakeFiles/compile.dir/symbol_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile.dir/symbol_table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chill/Documents/workspace/cs5300/Final_Project/src/symbol_table.cpp -o CMakeFiles/compile.dir/symbol_table.cpp.s

CMakeFiles/compile.dir/symbol_table.cpp.o.requires:

.PHONY : CMakeFiles/compile.dir/symbol_table.cpp.o.requires

CMakeFiles/compile.dir/symbol_table.cpp.o.provides: CMakeFiles/compile.dir/symbol_table.cpp.o.requires
	$(MAKE) -f CMakeFiles/compile.dir/build.make CMakeFiles/compile.dir/symbol_table.cpp.o.provides.build
.PHONY : CMakeFiles/compile.dir/symbol_table.cpp.o.provides

CMakeFiles/compile.dir/symbol_table.cpp.o.provides.build: CMakeFiles/compile.dir/symbol_table.cpp.o


CMakeFiles/compile.dir/OffSets.cpp.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/OffSets.cpp.o: /home/chill/Documents/workspace/cs5300/Final_Project/src/OffSets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/compile.dir/OffSets.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile.dir/OffSets.cpp.o -c /home/chill/Documents/workspace/cs5300/Final_Project/src/OffSets.cpp

CMakeFiles/compile.dir/OffSets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile.dir/OffSets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chill/Documents/workspace/cs5300/Final_Project/src/OffSets.cpp > CMakeFiles/compile.dir/OffSets.cpp.i

CMakeFiles/compile.dir/OffSets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile.dir/OffSets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chill/Documents/workspace/cs5300/Final_Project/src/OffSets.cpp -o CMakeFiles/compile.dir/OffSets.cpp.s

CMakeFiles/compile.dir/OffSets.cpp.o.requires:

.PHONY : CMakeFiles/compile.dir/OffSets.cpp.o.requires

CMakeFiles/compile.dir/OffSets.cpp.o.provides: CMakeFiles/compile.dir/OffSets.cpp.o.requires
	$(MAKE) -f CMakeFiles/compile.dir/build.make CMakeFiles/compile.dir/OffSets.cpp.o.provides.build
.PHONY : CMakeFiles/compile.dir/OffSets.cpp.o.provides

CMakeFiles/compile.dir/OffSets.cpp.o.provides.build: CMakeFiles/compile.dir/OffSets.cpp.o


CMakeFiles/compile.dir/StrTable.cpp.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/StrTable.cpp.o: /home/chill/Documents/workspace/cs5300/Final_Project/src/StrTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/compile.dir/StrTable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile.dir/StrTable.cpp.o -c /home/chill/Documents/workspace/cs5300/Final_Project/src/StrTable.cpp

CMakeFiles/compile.dir/StrTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile.dir/StrTable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chill/Documents/workspace/cs5300/Final_Project/src/StrTable.cpp > CMakeFiles/compile.dir/StrTable.cpp.i

CMakeFiles/compile.dir/StrTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile.dir/StrTable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chill/Documents/workspace/cs5300/Final_Project/src/StrTable.cpp -o CMakeFiles/compile.dir/StrTable.cpp.s

CMakeFiles/compile.dir/StrTable.cpp.o.requires:

.PHONY : CMakeFiles/compile.dir/StrTable.cpp.o.requires

CMakeFiles/compile.dir/StrTable.cpp.o.provides: CMakeFiles/compile.dir/StrTable.cpp.o.requires
	$(MAKE) -f CMakeFiles/compile.dir/build.make CMakeFiles/compile.dir/StrTable.cpp.o.provides.build
.PHONY : CMakeFiles/compile.dir/StrTable.cpp.o.provides

CMakeFiles/compile.dir/StrTable.cpp.o.provides.build: CMakeFiles/compile.dir/StrTable.cpp.o


CMakeFiles/compile.dir/parser.cpp.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/parser.cpp.o: parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/compile.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile.dir/parser.cpp.o -c /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp

CMakeFiles/compile.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp > CMakeFiles/compile.dir/parser.cpp.i

CMakeFiles/compile.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp -o CMakeFiles/compile.dir/parser.cpp.s

CMakeFiles/compile.dir/parser.cpp.o.requires:

.PHONY : CMakeFiles/compile.dir/parser.cpp.o.requires

CMakeFiles/compile.dir/parser.cpp.o.provides: CMakeFiles/compile.dir/parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/compile.dir/build.make CMakeFiles/compile.dir/parser.cpp.o.provides.build
.PHONY : CMakeFiles/compile.dir/parser.cpp.o.provides

CMakeFiles/compile.dir/parser.cpp.o.provides.build: CMakeFiles/compile.dir/parser.cpp.o


CMakeFiles/compile.dir/scanner.cpp.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/scanner.cpp.o: scanner.cpp
CMakeFiles/compile.dir/scanner.cpp.o: parser.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/compile.dir/scanner.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile.dir/scanner.cpp.o -c /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/scanner.cpp

CMakeFiles/compile.dir/scanner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile.dir/scanner.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/scanner.cpp > CMakeFiles/compile.dir/scanner.cpp.i

CMakeFiles/compile.dir/scanner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile.dir/scanner.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/scanner.cpp -o CMakeFiles/compile.dir/scanner.cpp.s

CMakeFiles/compile.dir/scanner.cpp.o.requires:

.PHONY : CMakeFiles/compile.dir/scanner.cpp.o.requires

CMakeFiles/compile.dir/scanner.cpp.o.provides: CMakeFiles/compile.dir/scanner.cpp.o.requires
	$(MAKE) -f CMakeFiles/compile.dir/build.make CMakeFiles/compile.dir/scanner.cpp.o.provides.build
.PHONY : CMakeFiles/compile.dir/scanner.cpp.o.provides

CMakeFiles/compile.dir/scanner.cpp.o.provides.build: CMakeFiles/compile.dir/scanner.cpp.o


# Object files for target compile
compile_OBJECTS = \
"CMakeFiles/compile.dir/main.cpp.o" \
"CMakeFiles/compile.dir/RegisterPool.cpp.o" \
"CMakeFiles/compile.dir/symbol_table.cpp.o" \
"CMakeFiles/compile.dir/OffSets.cpp.o" \
"CMakeFiles/compile.dir/StrTable.cpp.o" \
"CMakeFiles/compile.dir/parser.cpp.o" \
"CMakeFiles/compile.dir/scanner.cpp.o"

# External object files for target compile
compile_EXTERNAL_OBJECTS =

compile: CMakeFiles/compile.dir/main.cpp.o
compile: CMakeFiles/compile.dir/RegisterPool.cpp.o
compile: CMakeFiles/compile.dir/symbol_table.cpp.o
compile: CMakeFiles/compile.dir/OffSets.cpp.o
compile: CMakeFiles/compile.dir/StrTable.cpp.o
compile: CMakeFiles/compile.dir/parser.cpp.o
compile: CMakeFiles/compile.dir/scanner.cpp.o
compile: CMakeFiles/compile.dir/build.make
compile: /usr/lib/x86_64-linux-gnu/libfl.so
compile: CMakeFiles/compile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable compile"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/compile.dir/build: compile

.PHONY : CMakeFiles/compile.dir/build

CMakeFiles/compile.dir/requires: CMakeFiles/compile.dir/main.cpp.o.requires
CMakeFiles/compile.dir/requires: CMakeFiles/compile.dir/RegisterPool.cpp.o.requires
CMakeFiles/compile.dir/requires: CMakeFiles/compile.dir/symbol_table.cpp.o.requires
CMakeFiles/compile.dir/requires: CMakeFiles/compile.dir/OffSets.cpp.o.requires
CMakeFiles/compile.dir/requires: CMakeFiles/compile.dir/StrTable.cpp.o.requires
CMakeFiles/compile.dir/requires: CMakeFiles/compile.dir/parser.cpp.o.requires
CMakeFiles/compile.dir/requires: CMakeFiles/compile.dir/scanner.cpp.o.requires

.PHONY : CMakeFiles/compile.dir/requires

CMakeFiles/compile.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/compile.dir/cmake_clean.cmake
.PHONY : CMakeFiles/compile.dir/clean

CMakeFiles/compile.dir/depend: parser.cpp
CMakeFiles/compile.dir/depend: parser.hpp
CMakeFiles/compile.dir/depend: scanner.cpp
	cd /home/chill/Documents/workspace/cs5300/Final_Project/Compiler && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chill/Documents/workspace/cs5300/Final_Project/src /home/chill/Documents/workspace/cs5300/Final_Project/src /home/chill/Documents/workspace/cs5300/Final_Project/Compiler /home/chill/Documents/workspace/cs5300/Final_Project/Compiler /home/chill/Documents/workspace/cs5300/Final_Project/Compiler/CMakeFiles/compile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/compile.dir/depend

