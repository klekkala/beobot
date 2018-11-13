

//Sender Code
//#include "RCrecieve.h"
#include "DifferentialDrive.h"















LeftMotor = Motor();
RightMotor = Motor();

LeftEncoder = Encoder(2, 3, 18);
RightEncoder = Encoder(19, 20, 21);



LeftPositionControl = PositionControl();
LeftPositionControl = PositionControl();

LeftSpeedControl = SpeedControl();
LeftSpeedControl = SpeedControl();










void setup() {
  //rcsetup();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM20);
  //TCCR2B = _BV(WGM22) | _BV(CS22);
  //OCR2A = 250;
  //OCR2B = 250;

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  
  
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  pinMode(12, OUTPUT);

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
  float ver = ((c-1000)/1000)*255;
  float hor = ((b-1000)/1000)*255;
  float scaler = a;
  float reverse = d;

  //c is right vertical
  //a is left vertical
  //b is right horizontal
  //d is reverse or forward switch


if (ver <=1500 && digitalRead(reverse) == HIGH){
     digitalWrite(relay, LOW);
  }

  else{
    CalculateTankDrive(hor, ver)
  }
  //digitalWrite(10,LOW);
  //digitalWrite(11,HIGH);
  //delay(100);
}
