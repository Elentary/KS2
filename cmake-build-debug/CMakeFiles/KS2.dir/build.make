# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Dmitriy\source\repos\KS2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\KS2.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\KS2.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\KS2.dir\flags.make

CMakeFiles\KS2.dir\Client\Client.cpp.obj: CMakeFiles\KS2.dir\flags.make
CMakeFiles\KS2.dir\Client\Client.cpp.obj: ..\Client\Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KS2.dir/Client/Client.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\KS2.dir\Client\Client.cpp.obj /FdCMakeFiles\KS2.dir\ /FS -c C:\Users\Dmitriy\source\repos\KS2\Client\Client.cpp
<<

CMakeFiles\KS2.dir\Client\Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KS2.dir/Client/Client.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\KS2.dir\Client\Client.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dmitriy\source\repos\KS2\Client\Client.cpp
<<

CMakeFiles\KS2.dir\Client\Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KS2.dir/Client/Client.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\KS2.dir\Client\Client.cpp.s /c C:\Users\Dmitriy\source\repos\KS2\Client\Client.cpp
<<

CMakeFiles\KS2.dir\Client\Client.cpp.obj.requires:

.PHONY : CMakeFiles\KS2.dir\Client\Client.cpp.obj.requires

CMakeFiles\KS2.dir\Client\Client.cpp.obj.provides: CMakeFiles\KS2.dir\Client\Client.cpp.obj.requires
	$(MAKE) -f CMakeFiles\KS2.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\KS2.dir\Client\Client.cpp.obj.provides.build
.PHONY : CMakeFiles\KS2.dir\Client\Client.cpp.obj.provides

CMakeFiles\KS2.dir\Client\Client.cpp.obj.provides.build: CMakeFiles\KS2.dir\Client\Client.cpp.obj


CMakeFiles\KS2.dir\KS2\Server.cpp.obj: CMakeFiles\KS2.dir\flags.make
CMakeFiles\KS2.dir\KS2\Server.cpp.obj: ..\KS2\Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/KS2.dir/KS2/Server.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\KS2.dir\KS2\Server.cpp.obj /FdCMakeFiles\KS2.dir\ /FS -c C:\Users\Dmitriy\source\repos\KS2\KS2\Server.cpp
<<

CMakeFiles\KS2.dir\KS2\Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KS2.dir/KS2/Server.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\KS2.dir\KS2\Server.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dmitriy\source\repos\KS2\KS2\Server.cpp
<<

CMakeFiles\KS2.dir\KS2\Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KS2.dir/KS2/Server.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\KS2.dir\KS2\Server.cpp.s /c C:\Users\Dmitriy\source\repos\KS2\KS2\Server.cpp
<<

CMakeFiles\KS2.dir\KS2\Server.cpp.obj.requires:

.PHONY : CMakeFiles\KS2.dir\KS2\Server.cpp.obj.requires

CMakeFiles\KS2.dir\KS2\Server.cpp.obj.provides: CMakeFiles\KS2.dir\KS2\Server.cpp.obj.requires
	$(MAKE) -f CMakeFiles\KS2.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\KS2.dir\KS2\Server.cpp.obj.provides.build
.PHONY : CMakeFiles\KS2.dir\KS2\Server.cpp.obj.provides

CMakeFiles\KS2.dir\KS2\Server.cpp.obj.provides.build: CMakeFiles\KS2.dir\KS2\Server.cpp.obj


# Object files for target KS2
KS2_OBJECTS = \
"CMakeFiles\KS2.dir\Client\Client.cpp.obj" \
"CMakeFiles\KS2.dir\KS2\Server.cpp.obj"

# External object files for target KS2
KS2_EXTERNAL_OBJECTS =

KS2.exe: CMakeFiles\KS2.dir\Client\Client.cpp.obj
KS2.exe: CMakeFiles\KS2.dir\KS2\Server.cpp.obj
KS2.exe: CMakeFiles\KS2.dir\build.make
KS2.exe: CMakeFiles\KS2.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable KS2.exe"
	"C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\KS2.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\KS2.dir\objects1.rsp @<<
 /out:KS2.exe /implib:KS2.lib /pdb:C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug\KS2.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\KS2.dir\build: KS2.exe

.PHONY : CMakeFiles\KS2.dir\build

CMakeFiles\KS2.dir\requires: CMakeFiles\KS2.dir\Client\Client.cpp.obj.requires
CMakeFiles\KS2.dir\requires: CMakeFiles\KS2.dir\KS2\Server.cpp.obj.requires

.PHONY : CMakeFiles\KS2.dir\requires

CMakeFiles\KS2.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KS2.dir\cmake_clean.cmake
.PHONY : CMakeFiles\KS2.dir\clean

CMakeFiles\KS2.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Dmitriy\source\repos\KS2 C:\Users\Dmitriy\source\repos\KS2 C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug C:\Users\Dmitriy\source\repos\KS2\cmake-build-debug\CMakeFiles\KS2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\KS2.dir\depend

