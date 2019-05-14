//Sender Code
#include "RCrecieve.h"


void setup() {
  Serial.begin(9600);
  rcsetup();
}

void loop() {
  int i;
  int channels = 6;
  float ch[channels];
    for(i=0; i< channels; i++){
    ch[i] = pulseIn(i, HIGH, 25000); // Read the pulse width of 
  }
  float r = ch[4];
  float l = ch[3];
  float lpwm = ((l-990)/1000)*255;
  float rpwm = ((r-990)/1000)*255;
  Serial.println(lpwm);
  Serial.println("break1");
  Serial.println(rpwm); 
  Serial.println("break");

  if(lpwm < 0)
  lpwm = 0;

  if(rpwm < 0)
  rpwm = 0;
  analogWrite(6, lpwm);
  analogWrite(7, rpwm);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}
