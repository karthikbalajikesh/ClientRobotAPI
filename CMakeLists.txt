cmake_minimum_required(VERSION 3.5.1)

### CMAKE FILE for Client Program on top of Jetson Nano

## Dependencies:
# 1. Realsense library
# 2. Socket Library
# 3. OpenCV
# 4. Serialization Library (boost)
# 5. Threads

############### Project setup #########################
project(Client)

############### Compiler Setup #######################
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE Debug)

############### Adding Dependancies ###################

# 1. Realsense Library
find_package(realsense2 REQUIRED)

# 2. OpenCV
set(OpenCV_Dir "/home/karthik/opencv4/installation/OpenCV-master/lib/cmake/opencv4")
set(CMAKE_PREFIX_PATH "${OpenCV_Dir};${CMAKE_PREFIX_PATH}")
find_package(OpenCV 4.3.0 REQUIRED)

# 3. Threads
find_package(Threads REQUIRED)

############### Adding Source Files ####################
file(GLOB HELPERSOURCES "src/DepthCamera/*.cpp")
file(GLOB LANESOURCES "src/LaneDetector/*.cpp")
file(GLOB CLIENTSOURCES "src/Client/*.cpp")
include_directories(include)

# Appending all dependency libraries
set(LIBS "${realsense2_LIBRARY};${OpenCV_LIBS};${CMAKE_THREAD_LIBS_INIT}")

############### Adding Library ########################
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "../lib")
# 1. Realsense Helper
add_library(helper SHARED ${HELPERSOURCES})
target_link_libraries(helper ${LIBS})

#2. Lane Detector
add_library(LaneDetector SHARED ${LANESOURCES})
target_link_libraries(LaneDetector ${LIBS})

#3. Client
add_library(Client SHARED ${CLIENTSOURCES})
target_link_libraries(Client ${LIBS})

############## Appending custom libs to libs #########
FILE(GLOB CUSTOMLIBS "lib/*")
set(LIBS "${CUSTOMLIBS};${LIBS}")

############### Adding Executables #####################
FILE(GLOB TESTFILES "test/*")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")
add_executable(check ${TESTFILES})
target_link_libraries(check ${LIBS})
