/**
* This file is part of ORB-SLAM2.
*
* Copyright (C) 2014-2016 Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
* For more information see <https://github.com/raulmur/ORB_SLAM2>
*
* ORB-SLAM2 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ORB-SLAM2 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with ORB-SLAM2. If not, see <http://www.gnu.org/licenses/>.
*/


#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>

#include <geometry_msgs/PoseStamped.h> 
// #include <tf/tf.h> 
#include <tf/transform_datatypes.h> 
#include"../../../include/Converter.h"

#include<ros/ros.h>
// #include"std_msgs/String.h"
#include <sensor_msgs/Range.h>
#include <cv_bridge/cv_bridge.h>

#include<opencv2/core/core.hpp>

#include"../../../include/System.h"

//#include<python2.7/Python.h>
string trackingState;
int ST;
// float *pointerTS = &trackingState;

// tf::Transform new_transform;

using namespace std;

class ImageGrabber
{
public:
    ImageGrabber(ORB_SLAM2::System* pSLAM):mpSLAM(pSLAM){}

    void GrabImage(const sensor_msgs::ImageConstPtr& msg);

    ORB_SLAM2::System* mpSLAM;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Mono");
    ros::start();

    if(argc != 3)
    {
        cerr << endl << "Usage: rosrun ORB_SLAM2 Mono path_to_vocabulary path_to_settings" << endl;        
        ros::shutdown();
        return 1;
    }    

    // Create SLAM system. It initializes all system threads and gets ready to process frames.
    ORB_SLAM2::System SLAM(argv[1],argv[2],ORB_SLAM2::System::MONOCULAR,true);

    ImageGrabber igb(&SLAM);

    ros::NodeHandle nodeHandler;

    ros::Subscriber sub = nodeHandler.subscribe("/camera/image_raw", 1, &ImageGrabber::GrabImage,&igb);    
    ros::Publisher trackin_pub = nodeHandler.advertise<sensor_msgs::Range>("SLAM_TS", 1000);    
    // ros::Publisher camera_pose_pub = nodeHandler.advertise<geometry_msgs::PoseStamped>("SLAMCameraPose", 1000); 

    ros::Rate loop_rate(100); 

    while (ros::ok()) {        

        // //----Pose
        // geometry_msgs::PoseStamped pose;
        // pose.header.stamp = ros::Time::now();
        // pose.header.frame_id ="map";        
        // tf::poseTFToMsg(new_transform, pose.pose);
        
        // camera_pose_pub.publish(pose);

        //----TrackingS
        sensor_msgs::Range SLMAs;
        
        // std::stringstream ss;
        // ss << *pointerTS;  
        // SLMAs.range = ss.str();
        // msg.data = ss.str();
        // std::stringstream geek(trackingState);
        // geek >> ST;

        // SLMAs.header.stamp = ros::Time::now();
        // SLMAs.header.frame_id ="trackingState";  
        SLMAs.range = ST;
        trackin_pub.publish(SLMAs); 

        ros::spinOnce();           
        loop_rate.sleep();
    }  
    
    ros::spin();    

    // Stop all threads
    SLAM.Shutdown();

    // Save camera trajectory
    // SLAM.SaveKeyFrameTrajectoryTUM("/home/aaron/ORB_SLAM2/datosGenerados/KeyFrameTrajectory.txt");

    // Save the pointcloud       
    SLAM.SaveCloudMap("/home/aaron/ORB_SLAM2/datosGenerados/MapaDePuntosROS.xyz");    

    ros::shutdown();

    return 0;
}

void ImageGrabber::GrabImage(const sensor_msgs::ImageConstPtr& msg)
{
    // Copy the ros image message to cv::Mat.
    cv_bridge::CvImageConstPtr cv_ptr;
    try
    {
        cv_ptr = cv_bridge::toCvShare(msg);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    cv::Mat Tcw = mpSLAM->TrackMonocular(cv_ptr->image,cv_ptr->header.stamp.toSec());
        
    //------- Get TrackingState for publish
    ST = mpSLAM->GetTrackingState();
    


    // //------- Pose calculation
    // if( countNonZero(Tcw) ){
    //     cv::Mat Rwc = Tcw.rowRange(0,3).colRange(0,3).t(); // Rotation information
    //     cv::Mat twc = -Rwc*Tcw.rowRange(0,3).col(3); // translation information        
    //     vector<float> q = ORB_SLAM2::Converter::toQuaternion(Rwc);

    //     // std:: cout << "Rwc" << twc.at<float>(0, 0) << endl;
    //     // std:: cout << "twc" << twc << endl;
    //     // std:: cout << "q" << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << endl;
                
    //     new_transform.setOrigin(tf::Vector3(twc.at<float>(0, 0), twc.at<float>(0, 1), twc.at<float>(0, 2)));
    //     tf::Quaternion quaternion(q[0], q[1], q[2], q[3]);
    //     new_transform.setRotation(quaternion);    
    // } else {
    //     new_transform.setOrigin(tf::Vector3(0.0,0.0,0.0));
    //     tf::Quaternion quaternion(0.0, 0.0, 0.0, 1.0);
    //     new_transform.setRotation(quaternion);  
    // }
        
}


