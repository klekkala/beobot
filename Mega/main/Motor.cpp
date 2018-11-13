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
	pinMode(_dir, OUTPUT);
	pinMode(_lbrake, OUTPUT);
	pinMode(_hbrake, OUTPUT);
	pinMode(_pwm, OUTPUT);
}

// sets the motor's direction to forward
void Motor::setFwd()
{
	digitalWrite(_dir, HIGH);
	digitalWrite(_lbrake, HIGH);
	digitalWrite(_hbrake, HIGH);
}

// sets the motor's direction to backward
void Motor::setBack()
{
	digitalWrite(_dir, HIGH);
	digitalWrite(_lbrake, HIGH);
	digitalWrite(_hbrake, HIGH);
}

// sets the motor to freewheel
void Motor::setFree()
{
	digitalWrite(_dir, HIGH);
	digitalWrite(_lbrake, HIGH);
	digitalWrite(_hbrake, HIGH);
}

// sets the motor to low brake
void Motor::setBrake()
{
	digitalWrite(_dir, HIGH);
	digitalWrite(_lbrake, HIGH);
	digitalWrite(_hbrake, HIGH);
}

// sets the motor to high brake
void Motor::setStop()
{
	digitalWrite(_dir, HIGH);
	digitalWrite(_lbrake, HIGH);
	digitalWrite(_hbrake, HIGH);
}

// accepts an int, the PWM level, as a parameter
// sets the PWM output to the motor to the given int
// level must be between 0 and 255 inclusive
// behavior is undefined if level is outside this range
void Motor::setPWM(int level)
{
	analogWrite(_pwm, level);
}
