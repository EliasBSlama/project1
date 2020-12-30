#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "stdlib.h"
#include "std_msgs/String.h"
//#include "miniprojectsubscriber.h"


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
// Coordinates for the Sqaure
double xSquare1 = 0.2;
double ySqaure1 = 0;

double xSquare2 = 0.2;
double ySqaure2 = 0.2;

double xSquare3 = 0;
double ySqaure3 = 0.2;

double xSquare4 = 0;
double ySqaure4 = 0;



using namespace std;


bool goalReached = false;


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Areal of square: [%s]", msg->data.c_str());
  return;
}

int main(int argc, char** argv){ //

   int input;
   cout << "Choose your shape 1 for Square and 2 for rectangle: ";
   cin >> input;

// subscriber 
/**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "miniproject");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
  ros::Subscriber sub = n.subscribe("chatter", 1, chatterCallback);

// her til
   ros::init(argc, argv, "map_navigation_node");

         if(input = 1){
         goalReached = moveToGoal(xSquare1, ySqaure1);
         }
         if(input = 1){
         goalReached = moveToGoal(xSquare2, ySqaure2);
         }
         if(input = 1){
         goalReached = moveToGoal(xSquare3, ySqaure3);
         }
         if(input = 1){
         goalReached = moveToGoal(xSquare4, ySqaure4);
         }
            if(goalReached){
               ROS_INFO("Location has been reached");
               ros::spinOnce();
               return 0;
            }
       return 1;
   
      }
