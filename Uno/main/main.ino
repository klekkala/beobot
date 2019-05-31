#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include "Constants.h"

ros::NodeHandle nh;
geometry_msgs::Twist rftwist_msg;

ros::Publisher p("rftwist", &rftwist_msg);
//Loop scope variables
int channel[6] = {2, 3, 4, 5, 6, 7};
float value[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};


float rf_map(float value, float frommin, float frommax, float tomin, float tomax){
  if (value == 0)
    return 0;
  if (value < frommin)
    value = frommin;
  if (value > frommax)
    value = frommax;
  return (((value-frommin)*(tomax-tomin))/(frommax-frommin)) + tomin;
}


void setup() {


  //RC declarations
  pinMode(VERTICAL, INPUT);
  pinMode(HORIZONTAL, INPUT);
  pinMode(SCALE, INPUT);
  pinMode(REVERSE, INPUT);
  pinMode(GEAR, INPUT);
  pinMode(SWITCH, INPUT);
  nh.initNode();
  nh.advertise(p);

}

void loop() {
  value[HORIZONTAL] = pulseIn(channel[HORIZONTAL], HIGH, 50000); // Read the pulse width of
  value[VERTICAL] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  value[REVERSE] = pulseIn(channel[REVERSE], HIGH, 50000); // Read the pulse width of
  //value[SWITCH] = pulseIn(channel[SWITCH], HIGH, 50000); // Read the pulse width of
  //value[SCALE] = pulseIn(channel[SCALE], HIGH, 50000); // Read the pulse width oF

  if (value[REVERSE] > 1500){
    rftwist_msg.linear.x = rf_map(value[VERTICAL], 1000.00, 2000.00, -0.8, 1.00);
    rftwist_msg.angular.z = rf_map(value[HORIZONTAL], 1000.00, 2000.00, -1.00, 1.00);
    p.publish(&rftwist_msg);
  }

  nh.spinOnce();
}
