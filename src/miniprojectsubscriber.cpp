#include "stdlib.h"
#include "std_msgs/String.h"

std_msgs::String str_var;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
   str_var.data = msg->data;
   ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char** argv){ //

// subscriber
   ros::init(argc, argv, "projectroute");

   ros::NodeHandle nh;

   ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
