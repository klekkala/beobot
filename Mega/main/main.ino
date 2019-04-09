//License information

#include "Constants.h"
#include "DifferentialDrive.h"
#include "Encoder.h"
#include "Motor.h"
#include "PositionControl.h"
#include "SpeedControl.h"


Motor LeftMotor = Motor(LH_REVERSE, LH_STOP, LH_BRAKE, LH_PWM);
Motor RightMotor = Motor(RH_REVERSE, RH_STOP, RH_BRAKE, RH_PWM);

Encoder LeftEncoder = Encoder(LH_ENCODER_A, LH_ENCODER_B, LH_ENCODER_C, 100, 100);
Encoder RightEncoder = Encoder(RH_ENCODER_A, RH_ENCODER_B, RH_ENCODER_C, 100, 100);

SpeedControl LeftSpeedControl = SpeedControl(&LeftMotor, &LeftEncoder);
SpeedControl RightSpeedControl = SpeedControl(&RightMotor, &RightEncoder);

PositionControl LeftPositionControl = PositionControl(&LeftSpeedControl);
PositionControl RightPositionControl = PositionControl(&RightSpeedControl);


DifferentialDrive Driver = DifferentialDrive(&LeftPositionControl, &RightPositionControl, 10, 20);

//Loop scope variables
int channel[6] = {28, 29, 30, 31, 32, 33};
float value[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};


void setup() {

  //Left Encoder declarations
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(18, INPUT);
  attachInterrupt(0, LeftupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(1, LeftupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(5, LeftupdateCountC, RISING);//Initialize the interrupt pin

  //Right Encoder declarations
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  attachInterrupt(2, RightupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(3, RightupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(4, RightupdateCountC, RISING);//Initialize the interrupt pin


  //RC declarations
  pinMode(VERTICAL, INPUT);
  pinMode(HORIZONTAL, INPUT);
  pinMode(SCALE, INPUT);
  pinMode(REVERSE, INPUT);
  pinMode(STOP, INPUT);
  pinMode(SWITCH, INPUT);
  
  //Left Motor declarations
  pinMode(LH_PWM, OUTPUT);
  pinMode(LH_BRAKE, OUTPUT);
  digitalWrite(LH_BRAKE, HIGH);
  pinMode(LH_STOP, OUTPUT);
  digitalWrite(LH_STOP, HIGH);
  pinMode(LH_REVERSE, OUTPUT);
  digitalWrite(LH_REVERSE, HIGH);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH);

  //Left Motor declarations
  pinMode(RH_PWM, OUTPUT);
  pinMode(RH_BRAKE, OUTPUT);
  digitalWrite(RH_BRAKE, HIGH);
  pinMode(RH_STOP, OUTPUT);
  digitalWrite(RH_STOP, HIGH);
  pinMode(RH_REVERSE, OUTPUT);
  digitalWrite(RH_REVERSE, HIGH);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH);

  //Serial writing
  Serial.begin(115200);
}

void loop() {
  
  for(int i=0; i<6; i++){
    value[i] = pulseIn(channel[i], HIGH, 250000); // Read the pulse width of
  }

  Serial.print(channel[VERTICAL]);
  //Some RC preprocessing
  channel[VERTICAL] = ((channel[VERTICAL]-1000)/1000)*255;
  channel[HORIZONTAL] = ((channel[HORIZONTAL]-1000)/1000)*255;
  channel[SCALE] = map(1000, 990, 2000, 60, 150);
  
  if (channel[SWITCH] > 100){
    Serial.println("bye");
    //DRIVE(channels)
  }

  else{
    //Serial.read()
    Serial.println("hello");
  }
  
  delay(100);
}

void LeftupdateCountA(){
  LeftEncoder.updateCountA();
}

void LeftupdateCountB(){
  LeftEncoder.updateCountB();
}

void LeftupdateCountC(){
  LeftEncoder.updateCountC();
}

void RightupdateCountA(){
  RightEncoder.updateCountA();
}

void RightupdateCountB(){
  RightEncoder.updateCountB();
}

void RightupdateCountC(){
  RightEncoder.updateCountC();
}
