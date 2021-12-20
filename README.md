# ORBSLAM2_ROS_NOETIC
ORBSLAM2 adapted for Ubuntu 20 and ROS Noetic if neccesary.

NOTE: THIS VERSION SAVE MAP AFTER MONOCULAR ROS FINISH, AT PATH: /home/aaron/ORB_SLAM2/datosGenerados, YOU CAN CHANGE THIS AT ORB_SLAM2_ROS_NOETIC/Examples/ROS/ORB_SLAM2/src/ros_mono.cc IN LINE 123.

# Install modified Pangolin
I added Pangolin version compatible with Ubuntu 20 and ORB_SLAM2, so, we need to install it.

1. Enter Pangolin path
    1.1 ->  cd ORB_SLAM2_ROS_NOETIC/Pangolin
2. Build Pangolin
    2.1 ->  mkdir build && cd build
    2.2 ->  cmake ..
    2.3 ->  cmake --build .

3. Test Pangolin
    3.1 ->  cd ORB_SLAM2_ROS_NOETIC/Pangolin/examples/HelloPangolin
    3.2 ->  cmake -f CMakeLists.txt
    3.3 ->  cmake
    3.4 ->  ./HelloPangolin

# Install ORB_SLAM2
I added ORB_SLAM2 version compatible with Ubuntu 20 and ORB_SLAM2, so, for install and use just follow official steps at: https://github.com/raulmur/ORB_SLAM2