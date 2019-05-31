#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif
#include <ros.h>
#include <std_msgs/UInt8.h>
#include "Encoder.h"
#include "Constants.h"

ros::NodeHandle nh;

std_msgs::UInt8 lticks_m;
std_msgs::UInt8 rticks_m;
ros::Publisher lencoder("lenc", &lticks_m);
ros::Publisher rencoder("renc", &rticks_m);


Encoder LeftEncoder = Encoder(LH_ENCODER_B, LH_ENCODER_C, LH_ENCODER_A, deltaT, ticksPerRev);
Encoder RightEncoder = Encoder(RH_ENCODER_A, RH_ENCODER_C, RH_ENCODER_B, deltaT, ticksPerRev);
TickCounts counts;

bool enc0_0 = 1;
bool enc0_1 = 1;
bool enc0_5 = 1;

bool forward = true;
void setup() {

  //Left Encoder declarations
  pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(LH_ENCODER_C, INPUT);
  attachInterrupt(2, LeftupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(3, LeftupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(4, LeftupdateCountC, RISING);//Initialize the interrupt pin

  //Right Encoder declarations
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_C, INPUT);
  attachInterrupt(0, RightupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(1, RightupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(5, RightupdateCountC, RISING);//Initialize the interrupt pin

  nh.initNode();
  
  nh.advertise(lencoder);
  nh.advertise(rencoder);

}

void loop() {

  LeftEncoder.getSpeed(forward);
  RightEncoder.getSpeed(forward);
  lticks_m.data = LeftEncoder.getDistance();
  rticks_m.data = RightEncoder.getDistance();
  Serial.println(rticks_m.data);
  lencoder.publish(&lticks_m);
  rencoder.publish(&rticks_m);
  nh.spinOnce();
  delay(70);
}

void LeftupdateCountA(){
  LeftEncoder.updateCountA(forward);
}

void LeftupdateCountB(){
  LeftEncoder.updateCountB(forward);
}

void LeftupdateCountC(){
  LeftEncoder.updateCountC(forward);
}


void RightupdateCountA(){
  RightEncoder.updateCountA(forward);
}

void RightupdateCountB(){
  RightEncoder.updateCountB(forward);
}

void RightupdateCountC(){
  RightEncoder.updateCountC(forward);
}
