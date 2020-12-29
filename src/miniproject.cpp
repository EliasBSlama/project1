#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "stdlib.h"
#include "std_msgs/String.h"
#include "miniprojectsubscriber.h"


bool moveToGoal(double xGoal, double yGoal){

   //define a client for to send goal requests to the move_base server through a SimpleActionClient
   actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

   //wait for the action server to come up
   while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
   }

   move_base_msgs::MoveBaseGoal goal;

   //set up the frame parameters
   goal.target_pose.header.frame_id = "odom";
   goal.target_pose.header.stamp = ros::Time::now();

   // moving towards the goal

   goal.target_pose.pose.position.x =  xGoal;
   goal.target_pose.pose.position.y =  yGoal;
   goal.target_pose.pose.position.z =  0.0;
   goal.target_pose.pose.orientation.x = 0.0;
   goal.target_pose.pose.orientation.y = 0.0;
   goal.target_pose.pose.orientation.z = 0.0;
   goal.target_pose.pose.orientation.w = 1.0;

   ROS_INFO("Sending goal location ...");
   ac.sendGoal(goal);

   ac.waitForResult();

   if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
      ROS_INFO("You have reached the destination");
      return true;
   }
   else{
      ROS_INFO("The robot failed to reach the destination");
      return false;
   }

}


/** function declarations **/
// bool moveToGoal(double xGoal, double yGoal);
// char choose();



/** declare the coordinates of interest **/
double xMap1 = 0.2;
double yMap1 = 0;

bool goalReached = false;


//Er til subscriber
/*
std_msgs::UInt16 rfid;

void chatterCallback(const std_msgs::UInt16::ConstPtr& msg)
{
   rfid.data = msg->data;
   ROS_INFO("I heard: [%s]", msg->data);
   std::cout <<"I heard [%s]";
   //std::cout << str_var.data;
}

   // ros::init(argc, argv, "projectroute");

   // ros::NodeHandle n;

   // ros::Subscriber rfid = n.subscribe("chatter", 1000, chatterCallback);

*/

using namespace std;

int main(int argc, char** argv){ //

// subscriber 
/*
   ros::init(argc, argv, "projectroute");

   ros::NodeHandle nh;

   ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

   // std::cout << msg->data.c_str()
*/
// her til
   ros::Time::init();
   ros::Rate loop_rate(1000);
   ros::init(argc, argv, "map_navigation_node");
   
   ros::spinOnce();
  // int count = 1;
   while(foo::x != 1){
      //if(foo::x=1){
         std::cout <<"Wating for RFID ";
         //count++;
         loop_rate.sleep();
      }
   //}
         if(foo::x=1){
         std::cout <<"rfid succesfull";
         goalReached = moveToGoal(xMap1, yMap1);
         }
            if(goalReached){
               ROS_INFO("Location has been reached");
               ros::spinOnce();
               return 0;
            }
         //else{
            //ROS_INFO("Hard Luck!");
       //  }
      // while(destination !='1');
       return 1;
   
      }
