#include <ros/ros.h>
#include <example3_msgCustom/calculation.h>

using namespace example3_msgCustom;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "questioner");
    ros::NodeHandle n;
//   ros::Publisher pub = n.advertise<hri_ex3_msgCustom::calculation>("count", 1000);
    ros::Publisher pub = n.advertise<calculation>("calculation", 1000);

    int count = 0;
    ros::Rate rate(10);

    calculation msg;
    msg.opt = "minus";
    msg.num1 = 7;
    msg.num2 = 4;

    while(ros::ok()){
        count ++;
        ROS_INFO("questioning");

        pub.publish(msg);
        rate.sleep();
    }
    return 0;
}

/* calculation.msg -->
string opt
float32 num1
float32 num2
  */
