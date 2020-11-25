cmake_minimum_required(VERSION 2.8.3)
project(project1)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs move_base_msgs actionlib)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# Declare Kill Turtles C++ executable and rename to short name (in case catkin_make is used).
add_executable(${PROJECT_NAME}_project1 src/projectroute.cpp)
set_target_properties(${PROJECT_NAME}_project1 PROPERTIES OUTPUT_NAME projectroute PREFIX "")
# Link to Catkin libraries
target_link_libraries(${PROJECT_NAME}_project1
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

# Mark executables for installation
install(TARGETS
  ${PROJECT_NAME}_project1
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
