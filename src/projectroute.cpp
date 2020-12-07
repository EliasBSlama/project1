#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "stdlib.h"

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
double xTable1 = 4.15;
double yTable1 = -0.797;
double xTableDestination1 =3.82;
double yTableDestination1 =-4.09;
double xTable2 = 7.45;
double yTable2 = -1.67;
double xTableDestination2 = 0.444;
double yTableDestination2 =-3.65;

bool goalReached = false;
 int main(int argc, char** argv){
   ros::init(argc, argv, "map_navigation_node");
   ros::NodeHandle n;
   ros::spinOnce();


   int destination = '0';
   std::cout <<"Choose what table to move: 1 or 2: ";
   // do{
   std::cin >> destination;
   
   //    destination =choose();
      if (destination == 1){
         std::cout <<"moveToGoal succesfull";
         goalReached = moveToGoal(xTable1, yTable1);
      }
      if (destination == 1){
         if (goalReached){
            ROS_INFO("Congratulations, table number 1 reached, proceeding to destination!");
            ros::spinOnce();
            //ros::spinOnce();
         goalReached = moveToGoal(xTableDestination1, yTableDestination1);
            if(goalReached){
               ROS_INFO("Tables has been moved to desired location");
               ros::spinOnce();
            }
         }else{
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
   // }
   while(destination !='1');
   return 0;
}