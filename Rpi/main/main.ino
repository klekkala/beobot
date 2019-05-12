#include "Arduino.h"
#include "Encoder.h"
#include "Constants.h"


Encoder LeftEncoder = Encoder(LH_ENCODER_B, LH_ENCODER_C, LH_ENCODER_A, deltaT, ticksPerRev);
Encoder RightEncoder = Encoder(RH_ENCODER_A, RH_ENCODER_C, RH_ENCODER_B, deltaT, ticksPerRev);
TickCounts counts;

//Loop scope variables
int channel[6] = {28, 29, 30, 31, 32, 33};
float value[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

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


  //RC declarations
  pinMode(VERTICAL, INPUT);
  pinMode(HORIZONTAL, INPUT);
  pinMode(SCALE, INPUT);
  pinMode(STOP, INPUT);
  pinMode(SWITCH, INPUT);

  //Serial writing
  Serial.begin(115200);

}

void loop() {
    /*value[HORIZONTAL] = pulseIn(channel[HORIZONTAL], HIGH, 50000); // Read the pulse width of
  value[VERTICAL] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  value[STOP] = pulseIn(channel[STOP], HIGH, 50000); // Read the pulse width of
  value[SWITCH] = pulseIn(channel[SWITCH], HIGH, 50000); // Read the pulse width of
  value[SCALE] = pulseIn(channel[SCALE], HIGH, 50000); // Read the pulse width of*/

  //Serial.println("Start");
  //Serial.println(LeftEncoder.getSpeed(forward));
  Serial.println(RightEncoder.getSpeed(forward));
  //LeftEncoder.getDistance();
  RightEncoder.getDistance();
  //Serial.println("End");
  
  delay(100);
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
