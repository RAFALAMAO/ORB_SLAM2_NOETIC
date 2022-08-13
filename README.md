# ORB-SLAM2 for ROS Noetic, Ubuntu 20

<p align="center">
  <img
    src="/images/ORB_SLAM2.gif"
  >
</p>

ORBSLAM2 adapted for Ubuntu 20 and ROS Noetic if neccesary.

***NOTE 1: THIS VERSION SAVE POINTS CLOUD MAP AFTER MONOCULAR ROS FINISH, AT PATH WHERE YOU RUN ROS NODE, "CloudMapROS.xyz" AND "KeyFrameTrajectory.txt" FILES. YOU CAN CHANGE THIS AT ORB_SLAM2_NOETIC/Examples/ROS/ORB_SLAM2/src/ros_mono.cc IN LINE 123.***

***NOTE 1.1: IF CHANGE POINTS CLOUD MAP PATH, YOU NEED TO REBUILD ROS PACKAGE .***

# Install modified Pangolin
I added Pangolin version compatible with Ubuntu 20 and ORB_SLAM2, so, we need to install it.

=== Required Dependencies ===

* C++11

* OpenGL (Desktop / ES / ES2)

* Glew
 * (win) built automatically
 * (deb) sudo apt-get install libglew-dev
 * (mac) sudo port install glew

* CMake (for build environment)
 * (win) http://www.cmake.org/cmake/resources/software.html
 * (deb) sudo apt-get install cmake
 * (mac) sudo port install cmake

=== Building ===

1. Enter Pangolin path
    * cd ORB_SLAM2_NOETIC/Pangolin
2. Build Pangolin
    * mkdir build
    * cd build
    * cmake ..
    * make -j

3. Test Pangolin
    * cd ORB_SLAM2_NOETIC/Pangolin/examples/HelloPangolin
    * mkdir build
    * cd build
    * cmake ..
    * make -j
    * ./HelloPangolin

# Install ORB_SLAM2
I added ORB_SLAM2 version compatible with Ubuntu 20 and ORB_SLAM2, so, for install and use just follow official steps at: https://github.com/raulmur/ORB_SLAM2 (except clone official ORBSLAM2)

# Test:
Here is a [video](https://youtu.be/_syAilCknT4) testing it:

[![IMAGE ALT TEXT HERE](/images/ORB_SLAM2.gif)](https://youtu.be/_syAilCknT4)
