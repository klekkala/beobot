#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif
#include <ros.h>
#include <rosserial_arduino/Adc.h>
#include "Constants.h"

ros::NodeHandle nh;

rosserial_arduino::Adc rf_msg;
ros::Publisher p("rf", &rf_msg);
//Loop scope variables
int channel[6] = {2, 3, 4, 5, 6, 7};
float value[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

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
  //value[VERTICAL] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  value[REVERSE] = pulseIn(channel[REVERSE], HIGH, 50000); // Read the pulse width of
  //value[SWITCH] = pulseIn(channel[SWITCH], HIGH, 50000); // Read the pulse width of
  value[SCALE] = pulseIn(channel[SCALE], HIGH, 50000); // Read the pulse width oF

  rf_msg.adc0 = value[SCALE];
  rf_msg.adc1 = value[HORIZONTAL];
  rf_msg.adc2 = value[REVERSE];
  //adc_msg.adc3 = averageAnalog(3);
  //adc_msg.adc4 = averageAnalog(4);
  //adc_msg.adc5 = averageAnalog(5);
    
  p.publish(&rf_msg);

  nh.spinOnce();
}
