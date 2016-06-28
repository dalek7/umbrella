#include <ros/ros.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ex1");
    ros::NodeHandle n;

    int count = 0;
    ros::Rate rate(1);

    while(ros::ok()){
        ROS_INFO("%d", count);
        count ++;
        rate.sleep();
    }

    return 0;

}


// excute : $rosrun example1 hello
