# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dskittri/Desktop/my_boris_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dskittri/Desktop/my_boris_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/server_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_cpp.dir/flags.make

CMakeFiles/server_cpp.dir/src/main.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_cpp.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/main.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/main.cpp

CMakeFiles/server_cpp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/main.cpp > CMakeFiles/server_cpp.dir/src/main.cpp.i

CMakeFiles/server_cpp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/main.cpp -o CMakeFiles/server_cpp.dir/src/main.cpp.s

CMakeFiles/server_cpp.dir/src/Cluster.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/Cluster.cpp.o: ../src/Cluster.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server_cpp.dir/src/Cluster.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/Cluster.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/Cluster.cpp

CMakeFiles/server_cpp.dir/src/Cluster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/Cluster.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/Cluster.cpp > CMakeFiles/server_cpp.dir/src/Cluster.cpp.i

CMakeFiles/server_cpp.dir/src/Cluster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/Cluster.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/Cluster.cpp -o CMakeFiles/server_cpp.dir/src/Cluster.cpp.s

CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.o: ../src/ServerConfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/ServerConfig.cpp

CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/ServerConfig.cpp > CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.i

CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/ServerConfig.cpp -o CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.s

CMakeFiles/server_cpp.dir/src/Server.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/Server.cpp.o: ../src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server_cpp.dir/src/Server.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/Server.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/Server.cpp

CMakeFiles/server_cpp.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/Server.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/Server.cpp > CMakeFiles/server_cpp.dir/src/Server.cpp.i

CMakeFiles/server_cpp.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/Server.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/Server.cpp -o CMakeFiles/server_cpp.dir/src/Server.cpp.s

CMakeFiles/server_cpp.dir/src/Parser.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/Parser.cpp.o: ../src/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server_cpp.dir/src/Parser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/Parser.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/Parser.cpp

CMakeFiles/server_cpp.dir/src/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/Parser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/Parser.cpp > CMakeFiles/server_cpp.dir/src/Parser.cpp.i

CMakeFiles/server_cpp.dir/src/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/Parser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/Parser.cpp -o CMakeFiles/server_cpp.dir/src/Parser.cpp.s

CMakeFiles/server_cpp.dir/src/Connection.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/Connection.cpp.o: ../src/Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server_cpp.dir/src/Connection.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/Connection.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/Connection.cpp

CMakeFiles/server_cpp.dir/src/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/Connection.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/Connection.cpp > CMakeFiles/server_cpp.dir/src/Connection.cpp.i

CMakeFiles/server_cpp.dir/src/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/Connection.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/Connection.cpp -o CMakeFiles/server_cpp.dir/src/Connection.cpp.s

CMakeFiles/server_cpp.dir/src/Response.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/Response.cpp.o: ../src/Response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server_cpp.dir/src/Response.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/Response.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/Response.cpp

CMakeFiles/server_cpp.dir/src/Response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/Response.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/Response.cpp > CMakeFiles/server_cpp.dir/src/Response.cpp.i

CMakeFiles/server_cpp.dir/src/Response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/Response.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/Response.cpp -o CMakeFiles/server_cpp.dir/src/Response.cpp.s

CMakeFiles/server_cpp.dir/src/Cgi.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/Cgi.cpp.o: ../src/Cgi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server_cpp.dir/src/Cgi.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/Cgi.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/Cgi.cpp

CMakeFiles/server_cpp.dir/src/Cgi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/Cgi.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/Cgi.cpp > CMakeFiles/server_cpp.dir/src/Cgi.cpp.i

CMakeFiles/server_cpp.dir/src/Cgi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/Cgi.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/Cgi.cpp -o CMakeFiles/server_cpp.dir/src/Cgi.cpp.s

CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.o: CMakeFiles/server_cpp.dir/flags.make
CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.o: ../src/RequestHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.o -c /Users/dskittri/Desktop/my_boris_server/src/RequestHandler.cpp

CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dskittri/Desktop/my_boris_server/src/RequestHandler.cpp > CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.i

CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dskittri/Desktop/my_boris_server/src/RequestHandler.cpp -o CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.s

# Object files for target server_cpp
server_cpp_OBJECTS = \
"CMakeFiles/server_cpp.dir/src/main.cpp.o" \
"CMakeFiles/server_cpp.dir/src/Cluster.cpp.o" \
"CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.o" \
"CMakeFiles/server_cpp.dir/src/Server.cpp.o" \
"CMakeFiles/server_cpp.dir/src/Parser.cpp.o" \
"CMakeFiles/server_cpp.dir/src/Connection.cpp.o" \
"CMakeFiles/server_cpp.dir/src/Response.cpp.o" \
"CMakeFiles/server_cpp.dir/src/Cgi.cpp.o" \
"CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.o"

# External object files for target server_cpp
server_cpp_EXTERNAL_OBJECTS =

server_cpp: CMakeFiles/server_cpp.dir/src/main.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/Cluster.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/ServerConfig.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/Server.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/Parser.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/Connection.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/Response.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/Cgi.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/src/RequestHandler.cpp.o
server_cpp: CMakeFiles/server_cpp.dir/build.make
server_cpp: CMakeFiles/server_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable server_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_cpp.dir/build: server_cpp

.PHONY : CMakeFiles/server_cpp.dir/build

CMakeFiles/server_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_cpp.dir/clean

CMakeFiles/server_cpp.dir/depend:
	cd /Users/dskittri/Desktop/my_boris_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dskittri/Desktop/my_boris_server /Users/dskittri/Desktop/my_boris_server /Users/dskittri/Desktop/my_boris_server/cmake-build-debug /Users/dskittri/Desktop/my_boris_server/cmake-build-debug /Users/dskittri/Desktop/my_boris_server/cmake-build-debug/CMakeFiles/server_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_cpp.dir/depend

