
//Sender Code
//#include "RCrecieve.h"
#include "Constants.h"
#include "DifferentialDrive.h"
#include "Encoder.h"
#include "Motor.h"
#include "PositionControl.h"
#include "SpeedControl.h"













LeftMotor = Motor(dir1, lbrake1, hbrake1, pwm1);
RightMotor = Motor(dir2, lbrake2, hbrake2, pwm2);

LeftEncoder = Encoder(ch1a, ch1b, ch1c);
RightEncoder = Encoder(ch2a, ch2b, ch3c);

LeftSpeedControl = SpeedControl(LeftMotor, LeftEncoder);
RightSpeedControl = SpeedControl(RightMotor, RightEncoder);

LeftPositionControl = PositionControl(LeftSpeedControl);
RightPositionControl = PositionControl(RightSpeedControl);


Driver = DifferentialDrive(LeftPositionControl, RightPositionControl, 10, 20);







void setup() {
  //rcsetup();


  attachInterrupt(0, magnet_detect1, RISING);//Initialize the interrupt pin
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(42, INPUT);
  pinMode(43, INPUT);
  pinMode(44, INPUT);
  pinMode(45, INPUT);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);

  //Serial writing
  Serial.begin(115200);
}

void loop() {
  int i;
  float lp,rp;
  
  float a = pulseIn(2, HIGH, 250000); // Read the pulse width of
  float b = pulseIn(3, HIGH, 250000); // Read the pulse width of
  float c = pulseIn(4, HIGH, 250000); // Read the pulse width of
  float d = pulseIn(7, HIGH, 250000); // Read the pulse width of
  
  //c is right vertical
  //a is left vertical
  //b is right horizontal
  //d is reverse or forward switch

  float ver = ((c-1000)/1000)*255;
  float hor = ((b-1000)/1000)*255;
  float scaler = a;
  float reverse = d;


  if (ver <=1500 && digitalRead(reverse) == HIGH){
     digitalWrite(relay, LOW);
    }

  else{
    CalculateTankDrive(hor, ver)
  }
  
  //delay(100);
}
