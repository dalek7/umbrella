#include <ros/ros.h>
#include <example3_msgCustom/calculation.h>
// calculation.h will be automatically generated under
// ./msg_gen/cpp/include/example3_msgCustom
// so use the project name for pointing the file

// +1, if there is no msg, there will be an error like :
// [rosbuild] WARNING: rosbuild_genmsg() was called, but no .msg files were found
// note that rosbuild_genmsg() was called in the CMakeLists.txt

using namespace example3_msgCustom;

void cb(const calculation& msg)
{
    float ans;
    if(msg.opt == "plus")
        ans = msg.num1 + msg.num2;
    if(msg.opt == "minus")
        ans = msg.num1 - msg.num2;

    ROS_INFO("answer : %f", ans);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "answerer");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("calculation", 1000, cb);



    ros::spin();
    return 0;
}

