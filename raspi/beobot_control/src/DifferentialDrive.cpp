// DifferentialDrive
// by Andrew Kramer

// This class is completely untested!!!

#include <beobot_control/DifferentialDrive.h>
#include <math.h>

const double pi = 3.141592;

namespace beobot_control
{


DifferentialDrive::DifferentialDrive(PositionControl *lhWheel, 
								 PositionControl *rhWheel,
				 				 int wheelCirc, int wheelDistance)
{
	_leftWheel = lhWheel;
	_rightWheel = rhWheel;
	_wheelCirc = wheelCirc;
	_wheelDistance = wheelDistance;
	_xPosition = 0.0;
	_yPosition = 0.0;
	_theta = 0.0;	
	_degreesPerMillimeter = 360.0 / (double)wheelCirc;
}

//This function does'nt care about the amount of 
void DifferentialDrive::drive(int translational, double angular)
{
  //This converts the translational and angular velocities to left and right speeds
  int leftSpeed, rightSpeed;
  findSpeeds(translational, angular, leftSpeed, rightSpeed);

  //Find the current directions of the motors
  _leftdir = _leftWheel.dir
  _rightdir = _rightWheel.dir

  //If it's 
  if((!_leftdir and leftSpeed > 0) or (_leftdir and leftSpeed <= 0))
  	_leftWheel->toggledir();


  if((_rightdir == false and rightSpeed > 0) or (_rightdir == false and rightSpeed > 0))
  	_rightWheel->toggledir();


  _leftWheel->setPWM(leftSpeed);
  _rightWheel->setPWM(rightSpeed);

}





// finds wheel speed required to give the bot a specified angular and
// translational velocity
// positive angular will make the bot turn left
// negative angular will make the bot turn right
void DifferentialDrive::findSpeeds(int translational, double angular, 
									int &leftSpeed, int &rightSpeed)
{
	// calculate speed differential
	int speedDifferential = angular * ((double)_wheelDistance / 2.0);

	// calculate tangential speeds for left and right wheels;
	int leftTangential = translational - speedDifferential;
	int rightTangential = translational + speedDifferential;

	// calculate angular speeds for left and right wheels
	leftSpeed = (double)leftTangential * _degreesPerMillimeter;
	rightSpeed = (double)rightTangential * _degreesPerMillimeter;
}



void DifferentialDrive::update()
{

	//*** get distance from the subscriber ***
	double leftDegrees = _leftWheel->getDistance();
	double rightDegrees = _rightWheel->getDistance();
	//*********************************************
	
	sei();
	_leftWheel->adjustPWM();
	_rightWheel->adjustPWM();
	updatePosition();
}

}

