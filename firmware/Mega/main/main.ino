//License information

#include "Constants.h"
#include "Encoder.h"

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <nav_msgs/Odometry.h>

/* Messages
 * geometry_msgs/TwistWithCovariance twist
 * geometry_msgs/PoseWithCovariance pose
 * geometry_msgs/Vector3 linear_acceleration
 * geometry_msgs/AccelWithCovariance.msg
 * sensor_msgs/Range.msg
 * 
 * 
 * 
 * 
 */

const uint32_t PRINT_PERIOD = 1e6;  // print counts every second

ros::NodeHandle nh;
nav_msgs::Odometry wheelodom_msg;

ros::Publisher wheeltopic("wheelodom", &wheelodom_msg);
//ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);


//Loop scope variables
Encoder LeftEncoder = Encoder(LH_ENCODER_A, LH_ENCODER_B, deltaT, ticksPerRev);
Encoder RightEncoder = Encoder(RH_ENCODER_A, RH_ENCODER_B, deltaT, ticksPerRev);

TickCounts counts;


void setup() {


  //Left Encoder declarations
  pinMode(LH_ENCODER_A, INPUT_PULLUP);
  pinMode(LH_ENCODER_B, INPUT_PULLUP);
  attachInterrupt(0, LeftupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(1, LeftupdateCountB, RISING);//Initialize the interrupt pin

  //Right Encoder declarations
  pinMode(RH_ENCODER_A, INPUT_PULLUP);
  pinMode(RH_ENCODER_B, INPUT_PULLUP);
  attachInterrupt(0, RightupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(1, RightupdateCountB, RISING);//Initialize the interrupt pin

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
  
  //Serial writing (DEBUG) Serial.begin(115200);
  nh.initNode();
  nh.advertise(p);
}



void loop() {
  LeftSpeed = LeftEncoder.getSpeed();
  LeftDistance = LeftEncoder.getDistance();
  //LeftCounts = LeftEncoder.getCounts()

  RightSpeed = RightEncoder.getSpeed();
  RightDistance = RightEncoder.getDistance();
  //RightCounts = LeftEncoder.getCounts()
  
  // Fill up all the data into ROS messages
  current_time = ros::Time::now();

  //compute odometry in a typical way given the velocities of the robot
  double dt = (current_time - last_time).toSec();
  double delta_x = (vx * cos(th) - vy * sin(th)) * dt;
  double delta_y = (vx * sin(th) + vy * cos(th)) * dt;
  double delta_th = vth * dt;

  x += delta_x;
  y += delta_y;
  th += delta_th;



  //since all odometry is 6DOF we'll need a quaternion created from yaw
  geometry_msgs::Quaternion wheelodom_quat = tf::createQuaternionMsgFromYaw(th);

  //first, we'll publish the transform over tf
  geometry_msgs::TransformStamped wheelodom_trans;
  wheelodom_trans.header.stamp = current_time;
  wheelodom_trans.header.frame_id = "wheelodom";
  wheelodom_trans.child_frame_id = "base_link";

  wheelodom_trans.transform.translation.x = x;
  wheelodom_trans.transform.translation.y = y;
  wheelodom_trans.transform.translation.z = 0.0;
  wheelodom_trans.transform.rotation = wheelodom_quat;

  //send the transform
  wheelodom_broadcaster.sendTransform(wheelodom_trans);

  //next, we'll publish the odometry message over ROS
  wheelodom_trans.header.stamp = current_time;
  wheelodom_trans.header.frame_id = "odom";

  //set the position
  wheelodom.pose.pose.position.x = x;
  wheelodom.pose.pose.position.y = y;
  wheelodom.pose.pose.position.z = 0.0;
  wheelodom.pose.pose.orientation = wheelodom_quat;

  //set the velocity
  wheelodom.child_frame_id = "base_link";
  wheelodom.twist.twist.linear.x = vx;
  wheelodom.twist.twist.linear.y = vy;
  wheelodom.twist.twist.angular.z = vth;

  //publish the message
  wheelodom_trans.publish(wheelodom_trans);

  // publish all the messages
  wheeltopic.publish(&rftwist_msg);

  nh.spinOnce();
}



void LeftupdateCountA(){
  if(digitalRead(LH_ENCODER_B)==LOW){
    LeftEncoder.updateCountA(TRUE);
  }
  else{
    LeftEncoder.updateCountA(FALSE);
  }
}

void LeftupdateCountB(){
  if(digitalRead(LH_ENCODER_A)==LOW){
    LeftEncoder.updateCountB(TRUE);
  }
  else{
    LeftEncoder.updateCountB(FALSE);
  }
}


void RightupdateCountA(){
  if(digitalRead(RH_ENCODER_B)==LOW){
    RightEncoder.updateCountA(TRUE);
  }
  else{
    RightEncoder.updateCountA(FALSE);
  }
}

void RightupdateCountB(){
  if(digitalRead(RH_ENCODER_A)==LOW){
    RightEncoder.updateCountB(TRUE);
  }
  else{
    RightEncoder.updateCountB(FALSE);
  }
}
