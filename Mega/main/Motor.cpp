// Motor.cpp
// by Andrew Kramer

// Provides low-level control of a the speed and direction of a single DC motor
// by means of a motor driver such as the TB6612FNG

#include "Arduino.h"
#include "Motor.h"

// accepts three ints as parameters: 
//    the pin numbers for the direction control pins
//    and the pin number of the pwm pin
Motor::Motor(int dir, int lbrake, int hbrake, int pwm)
{
	_dir = dir;
	_lbrake = lbrake;
	_hbrake = hbrake;
	_pwm = pwm;
 _forward = 1;
 _neutral = 1;
 _clutch = 0;
	pinMode(_dir, OUTPUT);
	pinMode(_lbrake, OUTPUT);
	pinMode(_hbrake, OUTPUT);
	pinMode(_pwm, OUTPUT);
}

// sets the motor's direction to forward
void Motor::setFwd()
{
  if(!_forward or _neutral){
    Serial.println("hello");
    analogWrite(_pwm, 0);
    digitalWrite(_dir, LOW);
    digitalWrite(_lbrake, LOW);
    digitalWrite(_hbrake, LOW);
    /*unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish
        delayStart = millis();   // start delay
  delayRunning = true; // not finished yet
if (delayRunning && ((millis() - delayStart) >= 1000000)) {
    delayRunning = false;
    Serial.println("Turned LED Off");
  }
      Serial.println("del");
    }*/
    delay(1000);
    _forward = 1;
    _neutral = 0;
    Serial.println("delay");
}

}
// sets the motor's direction to backward
void Motor::setBack()
{
  if(_forward or _neutral){
    _clutch = 1;
    Serial.println("setback");
    analogWrite(_pwm, 0);
    digitalWrite(_dir, HIGH);
    digitalWrite(_lbrake, LOW);
    digitalWrite(_hbrake, LOW);
    /*unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish
        delayStart = millis();   // start delay
  delayRunning = true; // not finished yet
if (delayRunning && ((millis() - delayStart) >= 1000000)) {
    delayRunning = false;
    Serial.println("Turned LED Off");
  }*/
  delay(1000);
    _forward = 0;
    _neutral = 0;
    //_clutch = 0;
    Serial.println("delay");
  }
}

// sets the motor to low brake
void Motor::setStop()
{
  if(!_neutral){
    Serial.println("stop");
    _neutral = 1;
    digitalWrite(_dir, LOW);
    digitalWrite(_lbrake, HIGH);
     digitalWrite(_hbrake, HIGH);
    delay(1000);
  }
}

// sets the motor to high brake
void Motor::setBrake()
{
	//digitalWrite(_dir, HIGH);
	//digitalWrite(_lbrake, HIGH);
	//digitalWrite(_hbrake, HIGH);
}

// accepts an int, the PWM level, as a parameter
// sets the PWM output to the motor to the given int
// level must be between 0 and 255 inclusive
// behavior is undefined if level is outside this range
void Motor::setPWM(int level)
{
  /*int period = 200;
  unsigned long time_now = 0;
  time_now = millis();*/
	analogWrite(_pwm, level);
  Serial.println("level pwm");
  Serial.println(level);
 /*
  //Serial.println("PWM is");
  //Serial.println(level);
      while(millis() < time_now + period){
        //wait approx. [period] ms
    }*/
}
