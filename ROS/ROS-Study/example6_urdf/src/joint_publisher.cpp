#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

// roslaunch is enough to run. no need to rosrun
//$ roslaunch example6_urdf example6_urdf.launch

int main(int argc, char** argv) {
    ros::init(argc, argv, "joint_publisher");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
    ros::Rate loop_rate(30);

    const double degree = M_PI/180;

    // robot state
    double angle = 0, tinc = degree;
    double angle2 =0;
    int cnt=0;
    // message declarations
    sensor_msgs::JointState joint_state;

    while (ros::ok()) {
        //update joint_state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(14);
        joint_state.position.resize(14);
        joint_state.name[0] ="joint_head_z";
        joint_state.position[0] = angle;
        joint_state.name[1] ="joint_head_x";
        joint_state.position[1] = angle;
        joint_state.name[2] ="joint_leftArmUp_x";
        joint_state.position[2] = angle;
        joint_state.name[3] ="joint_leftArmUp_y";
        joint_state.position[3] = angle;
        joint_state.name[4] ="joint_leftArmUp_z";
        joint_state.position[4] = angle;
        joint_state.name[5] ="joint_leftArmDown_x";
        joint_state.position[5] = angle;
        joint_state.name[6] ="joint_leftArmDown_z";
        joint_state.position[6] = angle;
        joint_state.name[7] ="joint_leftHand_x";
        joint_state.position[7] = angle;
        joint_state.name[8] ="joint_rightArmUp_x";
        joint_state.position[8] = angle2;
        joint_state.name[9] ="joint_rightArmUp_y";
        joint_state.position[9] = angle2;
        joint_state.name[10] ="joint_rightArmUp_z";
        joint_state.position[10] = angle;
        joint_state.name[11] ="joint_rightArmDown_x";
        joint_state.position[11] = angle;
        joint_state.name[12] ="joint_rightArmDown_z";
        joint_state.position[12] = angle;
        joint_state.name[13] ="joint_rightHand_x";
        joint_state.position[13] = angle;

        //send the joint state and transform
        joint_pub.publish(joint_state);

        // Create new robot state
        cnt++;
        angle2 = sin(2*M_PI*cnt/100.0);
        angle += tinc;
        if (angle<-.5 || angle>0) tinc *= -1;


        printf("Created a new robot state: angle=%.2f\n", angle);
        // This will adjust as needed per iteration
        loop_rate.sleep();




    }


    return 0;
}
