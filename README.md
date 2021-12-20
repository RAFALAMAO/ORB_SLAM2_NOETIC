# ORBSLAM2_ROS_NOETIC
ORBSLAM2 adapted for Ubuntu 20 and ROS Noetic if neccesary.

***NOTE 1: THIS VERSION SAVE POINTS CLOUD MAP AFTER MONOCULAR ROS FINISH, AT PATH: /home/aaron/ORB_SLAM2_NOETIC/datosGenerados/MapaDePuntosROS.xyz, YOU CAN CHANGE THIS AT ORB_SLAM2_NOETIC/Examples/ROS/ORB_SLAM2/src/ros_mono.cc IN LINE 123.***

***NOTE 1.1: IF CHANGE MAP PATH, YOU NEED TO REBUILD ROS PACKAGE .***

# Install modified Pangolin
I added Pangolin version compatible with Ubuntu 20 and ORB_SLAM2, so, we need to install it.

1. Enter Pangolin path
    * cd ORB_SLAM2_NOETIC/Pangolin
2. Build Pangolin
    * mkdir build && cd build
    * cmake ..
    * cmake --build .

3. Test Pangolin
    * cd ORB_SLAM2_NOETIC/Pangolin/examples/HelloPangolin
    * cmake -f CMakeLists.txt
    * cmake
    * ./HelloPangolin

# Install ORB_SLAM2
I added ORB_SLAM2 version compatible with Ubuntu 20 and ORB_SLAM2, so, for install and use just follow official steps at: https://github.com/raulmur/ORB_SLAM2