#include <ros/ros.h>
#include <std_msgs/Int16.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::Int16>("count", 1000);

    int count=0;
    ros::Rate rate(10);
    std_msgs::Int16 msg;
    while(ros::ok()){
        count ++;
        ROS_INFO("talking: %d", count);

        msg.data = count;
        pub.publish(msg);
        rate.sleep();
    }
    return 0;
}
