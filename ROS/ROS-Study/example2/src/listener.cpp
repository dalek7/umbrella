#include <ros/ros.h>
#include <std_msgs/Int16.h>


void cb(const std_msgs::Int16& msg)
{
    ROS_INFO("listening : %d", msg.data);



}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("count", 1000, cb);



    ros::spin();
    return 0;
}

