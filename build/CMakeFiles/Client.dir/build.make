# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/karthik/dev/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karthik/dev/Client/build

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/src/Client/Client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Client/Client.cpp.o: ../src/Client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karthik/dev/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/src/Client/Client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Client/Client.cpp.o -c /home/karthik/dev/Client/src/Client/Client.cpp

CMakeFiles/Client.dir/src/Client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Client/Client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karthik/dev/Client/src/Client/Client.cpp > CMakeFiles/Client.dir/src/Client/Client.cpp.i

CMakeFiles/Client.dir/src/Client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Client/Client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karthik/dev/Client/src/Client/Client.cpp -o CMakeFiles/Client.dir/src/Client/Client.cpp.s

CMakeFiles/Client.dir/src/Client/Client.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/src/Client/Client.cpp.o.requires

CMakeFiles/Client.dir/src/Client/Client.cpp.o.provides: CMakeFiles/Client.dir/src/Client/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/src/Client/Client.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/src/Client/Client.cpp.o.provides

CMakeFiles/Client.dir/src/Client/Client.cpp.o.provides.build: CMakeFiles/Client.dir/src/Client/Client.cpp.o


CMakeFiles/Client.dir/src/tcp/tcp.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/tcp/tcp.cpp.o: ../src/tcp/tcp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karthik/dev/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/src/tcp/tcp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/tcp/tcp.cpp.o -c /home/karthik/dev/Client/src/tcp/tcp.cpp

CMakeFiles/Client.dir/src/tcp/tcp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/tcp/tcp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karthik/dev/Client/src/tcp/tcp.cpp > CMakeFiles/Client.dir/src/tcp/tcp.cpp.i

CMakeFiles/Client.dir/src/tcp/tcp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/tcp/tcp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karthik/dev/Client/src/tcp/tcp.cpp -o CMakeFiles/Client.dir/src/tcp/tcp.cpp.s

CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.requires

CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.provides: CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.provides

CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.provides.build: CMakeFiles/Client.dir/src/tcp/tcp.cpp.o


# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/src/Client/Client.cpp.o" \
"CMakeFiles/Client.dir/src/tcp/tcp.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

../lib/libClient.so: CMakeFiles/Client.dir/src/Client/Client.cpp.o
../lib/libClient.so: CMakeFiles/Client.dir/src/tcp/tcp.cpp.o
../lib/libClient.so: CMakeFiles/Client.dir/build.make
../lib/libClient.so: /home/karthik/Downloads/boost_1_73_0/stage/lib/libboost_serialization.so
../lib/libClient.so: /usr/lib/x86_64-linux-gnu/librealsense2.so.2.35.2
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_stitching.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_gapi.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_line_descriptor.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_cvv.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_superres.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_bgsegm.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_structured_light.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_phase_unwrapping.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_videostab.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_stereo.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_optflow.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_xphoto.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_surface_matching.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_sfm.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_img_hash.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_xobjdetect.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_bioinspired.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_intensity_transform.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_hdf.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_reg.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_dnn_objdetect.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_rapid.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_dpm.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_ccalib.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_dnn_superres.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_hfs.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_aruco.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_ximgproc.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_tracking.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_face.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_freetype.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_fuzzy.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_xfeatures2d.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_alphamat.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_saliency.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_datasets.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_rgbd.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_video.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_plot.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_text.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_shape.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_highgui.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_videoio.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_imgcodecs.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_dnn.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_quality.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_ml.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_objdetect.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_photo.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_calib3d.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_features2d.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_imgproc.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_flann.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_viz.so.4.3.0
../lib/libClient.so: /home/karthik/opencv4/installation/OpenCV-master/lib/libopencv_core.so.4.3.0
../lib/libClient.so: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/karthik/dev/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../lib/libClient.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: ../lib/libClient.so

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/src/Client/Client.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/src/tcp/tcp.cpp.o.requires

.PHONY : CMakeFiles/Client.dir/requires

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /home/karthik/dev/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karthik/dev/Client /home/karthik/dev/Client /home/karthik/dev/Client/build /home/karthik/dev/Client/build /home/karthik/dev/Client/build/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

