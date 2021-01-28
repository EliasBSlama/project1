#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "stdlib.h"
#include "std_msgs/String.h"

//Er til subscriber
std_msgs::String str_var;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
   str_var.data = msg->data;
   ROS_INFO("I heard: [%s]", msg->data.c_str());
}


   // ros::init(argc, argv, "projectroute");

   // ros::NodeHandle n;

   // ros::Subscriber rfid = n.subscribe("chatter", 1000, chatterCallback);


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

   /* moving towards the goal*/

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
bool moveToGoal(double xGoal, double yGoal);
// char choose();



/** declare the coordinates of interest **/
double xMap1 = 1;
double yMap1 = 0;
double xMap2 = 2;
double yMap2 = 0;
double xOrigo = 0;
double yOrigo = 0;
double xTable1 = 1;
double yTable1 = 0.5;
double xTableDestination1 = 2;
double yTableDestination1 = 0.5;
double xTable2 = 7.45;
double yTable2 = -1.67;
double xTableDestination2 = 0.444;
double yTableDestination2 =-3.65;



bool goalReached = false;

 int main(int argc, char** argv){ //

/*
   ros::init(argc, argv, "projectroute");

   ros::NodeHandle n;

   ros::Subscriber rfid = n.subscribe("chatter", 1000, chatterCallback);

   std::cout << rfid;
*/
   ros::init(argc, argv, "map_navigation_node");
   
//  ros::spinOnce();


   int destination = '0'; 
   std::cout <<"Choose what table to move: 1 or 2: ";
   std::cin >> destination;

      if (destination == 1 || 2){
         goalReached = moveToGoal(xMap1, yMap1);
      }
      if (destination == 1 || 2){
         goalReached = moveToGoal(xMap2, yMap2);
      }
      if (destination == 1 || 2){
         goalReached = moveToGoal(xOrigo, yOrigo);
         std::cout <<"Origo succesfull \n";
      }
      if (destination == 1){
         std::cout <<"moveToGoal succesfull \n";
         goalReached = moveToGoal(xTable1, yTable1);
      }
      std::cout <<"movetogoal2 succesfull \n";
      if (destination == 1){
         if (goalReached){
            ROS_INFO("Congratulations, table number 1 reached, proceeding to destination! \n");
            ros::spinOnce();
         goalReached = moveToGoal(xTableDestination1, yTableDestination1);
         }
         if (destination == 1){
         goalReached = moveToGoal(xOrigo, yOrigo);
      }
            if(goalReached){
               ROS_INFO("Tables has been moved to desired location \n");
               ros::spinOnce();
               return 0;
            }
         else{
            ROS_INFO("Hard Luck!");
         }
      }
      if (destination == 2){
         std::cout <<"moveToGoal succesfull";
         goalReached = moveToGoal(xTable2, yTable2);
      }
      if (destination == 2){
         if (goalReached){
            ROS_INFO("Congratulations, table number 2 reached, proceeding to destination!");
            ros::spinOnce();
            //ros::spinOnce();
         goalReached = moveToGoal(xTableDestination2, yTableDestination2);
            if(goalReached){
               ROS_INFO("Tables has been moved to desired location");
               ros::spinOnce();
            }
         }else{
            ROS_INFO("Hard Luck!");
         }
      }
   while(destination !='1');
   return 0;
}