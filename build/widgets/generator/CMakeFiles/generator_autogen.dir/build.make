# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /home/kapili3/k/game/gencmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kapili3/k/game/gencmake/build

# Utility rule file for generator_autogen.

# Include the progress variables for this target.
include widgets/generator/CMakeFiles/generator_autogen.dir/progress.make

widgets/generator/CMakeFiles/generator_autogen: widgets/generator/controller1.cc
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/controller1.h
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/controller_empty.cc
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/controller_empty.h
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/dgraph_schema.cc
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/dgraph_schema.h
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/js_class.cc
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/js_class.h
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/service_cc.cc
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/service_cc.h
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/service_h.cc
widgets/generator/CMakeFiles/generator_autogen: widgets/generator/service_h.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kapili3/k/game/gencmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target generator"
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && /usr/bin/cmake -E cmake_autogen /home/kapili3/k/game/gencmake/build/widgets/generator/CMakeFiles/generator_autogen.dir/AutogenInfo.cmake Release

widgets/generator/controller1.h: ../widgets/generator/templates/controller1.csp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kapili3/k/game/gencmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating controller1.h, controller1.cc"
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && drogon_ctl create view /home/kapili3/k/game/gencmake/widgets/generator/templates/controller1.csp

widgets/generator/controller1.cc: widgets/generator/controller1.h
	@$(CMAKE_COMMAND) -E touch_nocreate widgets/generator/controller1.cc

widgets/generator/controller_empty.h: ../widgets/generator/templates/controller_empty.csp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kapili3/k/game/gencmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating controller_empty.h, controller_empty.cc"
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && drogon_ctl create view /home/kapili3/k/game/gencmake/widgets/generator/templates/controller_empty.csp

widgets/generator/controller_empty.cc: widgets/generator/controller_empty.h
	@$(CMAKE_COMMAND) -E touch_nocreate widgets/generator/controller_empty.cc

widgets/generator/dgraph_schema.h: ../widgets/generator/templates/dgraph_schema.csp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kapili3/k/game/gencmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating dgraph_schema.h, dgraph_schema.cc"
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && drogon_ctl create view /home/kapili3/k/game/gencmake/widgets/generator/templates/dgraph_schema.csp

widgets/generator/dgraph_schema.cc: widgets/generator/dgraph_schema.h
	@$(CMAKE_COMMAND) -E touch_nocreate widgets/generator/dgraph_schema.cc

widgets/generator/js_class.h: ../widgets/generator/templates/js_class.csp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kapili3/k/game/gencmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Generating js_class.h, js_class.cc"
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && drogon_ctl create view /home/kapili3/k/game/gencmake/widgets/generator/templates/js_class.csp

widgets/generator/js_class.cc: widgets/generator/js_class.h
	@$(CMAKE_COMMAND) -E touch_nocreate widgets/generator/js_class.cc

widgets/generator/service_cc.h: ../widgets/generator/templates/service_cc.csp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kapili3/k/game/gencmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Generating service_cc.h, service_cc.cc"
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && drogon_ctl create view /home/kapili3/k/game/gencmake/widgets/generator/templates/service_cc.csp

widgets/generator/service_cc.cc: widgets/generator/service_cc.h
	@$(CMAKE_COMMAND) -E touch_nocreate widgets/generator/service_cc.cc

widgets/generator/service_h.h: ../widgets/generator/templates/service_h.csp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kapili3/k/game/gencmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Generating service_h.h, service_h.cc"
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && drogon_ctl create view /home/kapili3/k/game/gencmake/widgets/generator/templates/service_h.csp

widgets/generator/service_h.cc: widgets/generator/service_h.h
	@$(CMAKE_COMMAND) -E touch_nocreate widgets/generator/service_h.cc

generator_autogen: widgets/generator/CMakeFiles/generator_autogen
generator_autogen: widgets/generator/controller1.h
generator_autogen: widgets/generator/controller1.cc
generator_autogen: widgets/generator/controller_empty.h
generator_autogen: widgets/generator/controller_empty.cc
generator_autogen: widgets/generator/dgraph_schema.h
generator_autogen: widgets/generator/dgraph_schema.cc
generator_autogen: widgets/generator/js_class.h
generator_autogen: widgets/generator/js_class.cc
generator_autogen: widgets/generator/service_cc.h
generator_autogen: widgets/generator/service_cc.cc
generator_autogen: widgets/generator/service_h.h
generator_autogen: widgets/generator/service_h.cc
generator_autogen: widgets/generator/CMakeFiles/generator_autogen.dir/build.make

.PHONY : generator_autogen

# Rule to build all files generated by this target.
widgets/generator/CMakeFiles/generator_autogen.dir/build: generator_autogen

.PHONY : widgets/generator/CMakeFiles/generator_autogen.dir/build

widgets/generator/CMakeFiles/generator_autogen.dir/clean:
	cd /home/kapili3/k/game/gencmake/build/widgets/generator && $(CMAKE_COMMAND) -P CMakeFiles/generator_autogen.dir/cmake_clean.cmake
.PHONY : widgets/generator/CMakeFiles/generator_autogen.dir/clean

widgets/generator/CMakeFiles/generator_autogen.dir/depend:
	cd /home/kapili3/k/game/gencmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kapili3/k/game/gencmake /home/kapili3/k/game/gencmake/widgets/generator /home/kapili3/k/game/gencmake/build /home/kapili3/k/game/gencmake/build/widgets/generator /home/kapili3/k/game/gencmake/build/widgets/generator/CMakeFiles/generator_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : widgets/generator/CMakeFiles/generator_autogen.dir/depend

