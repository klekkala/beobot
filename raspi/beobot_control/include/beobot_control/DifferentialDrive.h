// DifferentialDrive
// by Andrew Kramer

#ifndef DifferentialDrive_h
#define DifferentialDrive_h

#include "Motor.h"
#include <math.h>

namespace beobot_control
{
class DifferentialDrive
{
public:
	DifferentialDrive(Motor*, Motor*, int wheelCirc, int wheelDistance);
	void drive(int translational, double angular, bool back);
	void update();
private:
	void findSpeeds(int translational, double angular, 
					int &leftSpeed, int &rightSpeed);
	int _wheelCirc; // circumference of wheels in millimeters
	int _wheelDistance; // distance between wheels in 
	double _degreesPerMillimeter;

	Motor *_leftMotor;
	Motor *_rightMotor;
};

}
#endif
