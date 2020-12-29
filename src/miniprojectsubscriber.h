#include <ros/ros.h>
#include "stdlib.h"
#include "std_msgs/String.h"
// #include "std_msgs/Int8.h"
#include "iostream"
#include "sstream"


/*
std_msgs::String rfid;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
   rfid.data = msg->data;
   ROS_INFO("I heard: [%s]", msg->data.c_str());
   std::cout <<"I heard [%s]";
}
*/
namespace foo
{




int main(int argc, char** argv){ //

while(true){
// subscriber

   ros::init(argc, argv, "projectroute");

   //ros::NodeHandle nh;

  // ros::Subscriber sub = nh.subscribe("chatter", 10, chatterCallback);

   //std::stringstream degree(rfid);

   //std::stringstream rfid;

   char = "Aalborg";

   rfid >> x;

   if(x = 1){
      std::cout <<"valute of rfid :"<< x;
   }
   ros::spinOnce();
}
   //return 0;
}
}
