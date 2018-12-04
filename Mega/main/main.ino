//License information

#include "Constants.h"
#include "DifferentialDrive.h"
#include "Encoder.h"
#include "Motor.h"
#include "PositionControl.h"
#include "SpeedControl.h"


LeftMotor = Motor(LH_REVERSE, LH_STOP, LH_BRAKE, LH_PWM);
RightMotor = Motor(RH_REVERSE, RH_STOP, RH_BRAKE, RH_PWM);

LeftEncoder = Encoder(LH_ENCODER_A, LH_ENCODER_B, LH_ENCODER_C);
RightEncoder = Encoder(RH_ENCODER_A, RH_ENCODER_B, RH_ENCODER_C);

LeftSpeedControl = SpeedControl(LeftMotor, LeftEncoder);
RightSpeedControl = SpeedControl(RightMotor, RightEncoder);

LeftPositionControl = PositionControl(LeftSpeedControl);
RightPositionControl = PositionControl(RightSpeedControl);


Driver = DifferentialDrive(LeftPositionControl, RightPositionControl, 10, 20);

//Loop scope variables
int ch = 6
int channel[ch] = {40, 41, 42, 43, 44, 45}
float value[ch] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}

void setup() {

  //Left Encoder declarations
  attachInterrupt(0, magnet_detect1, RISING);//Initialize the interrupt pin
  pinMode(1, INPUT);
  pinMode(2, INPUT);

  //Left Encoder declarations
  attachInterrupt(3, magnet_detect1, RISING);//Initialize the interrupt pin
  pinMode(1, INPUT);
  pinMode(2, INPUT);

  //RC declarations
  pinMode(VERTICAL, INPUT);
  pinMode(HORIZONTAL, INPUT);
  pinMode(SCALE, INPUT);
  pinMode(REVERSE, INPUT);
  pinMode(STOP, INPUT);
  pinMode(SAFE, INPUT);
  
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
  
  for(int i=0; i<ch; i++){
    float value[i] = pulseIn(channel[i], HIGH, 250000); // Read the pulse width of
  }

  //Some RC preprocessing
  channel[VERTICAL] = ((channel[VERTICAL]-1000)/1000)*255;
  channel[HORIZONTAL] = ((channel[HORIZONTAL]-1000)/1000)*255;
  channel[SCALE] = map(1000, 990, 2000, 60, 150);
  
  
  //delay(100);
}
