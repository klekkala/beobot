// Motor.cpp
// by Andrew Kramer

// Provides low-level control of a the speed and direction of a single DC motor
// by means of a motor driver such as the TB6612FNG

#include <beobot_control/Motor.h>

namespace beobot_control
{


//    accepts three ints as parameters: 
//    the pin numbers for the direction control pins
//    and the pin number of the pwm pin
Motor::Motor(int dir, int brake, int pwm)
{
	_dir = dir;
	_brake = brake;
	_pwm = pwm;
  _forward = 1;
  _neutral = 1;

  // Initialize all the relay switches
  //gpioSetMode(_dir, PI_OUTPUT);
  //gpioSetMode(_brake, PI_OUTPUT);

  // Set Relay voltages
  //gpioWrite(_dir, HIGH);
  //gpioWrite(_brake, HIGH);

  // Set 0 to DAC channel
  setPWM(0);
}

// sets the motor's direction to forward
void Motor::setFwd()
{
  if(_backward or _neutral){
    setPWM(0);
    delay(1000);
    //gpioWrite(_dir, HIGH);

    _forward = 1;
    _neutral = 0;
  }
}


// sets the motor's direction to backward
void Motor::setBack()
{
  if(_forward or _neutral){
    setPWM(0);
    delay(1000);
    //gpioWrite(_dir, LOW);

    _forward = 0;
    _neutral = 0;
  }
}


// sets the motor's direction to forward
void Motor::toggledir()
{
  if(_dir)
    setBack();
  else
    setFwd();
}



// sets the motor to high brake
void Motor::setBrake()
{
  setPWM(0);
  //gpioWrite(_brake, LOW);
}

// accepts an int, the PWM level, as a parameter
// sets the PWM output to the motor to the given int
// level must be between 0 and 255 inclusive
// behavior is undefined if level is outside this range
void Motor::setPWM(int level)
{
  assert(level <= 255 adn level > 0)
	//DAC8532_Out_Voltage(_pwm, (level/255)*3.3);
  _neutral = 1;

}



void Motor::adjustPWM(float velocity)
{

  //PID control

}

}