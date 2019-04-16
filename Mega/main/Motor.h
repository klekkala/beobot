// Motor
// by Andrew Kramer

// controls direction and pwm input to a DC motor

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
public:
	Motor(int dir, int lbrake, int hbrake, int pwm);
	void setFwd();
	void setBack();
	void setBrake();
	void setStop();
	void setPWM(int level);
  bool _clutch;
private:
	int _dir, _lbrake, _hbrake, _pwm;
  bool _forward, _neutral;
};

#endif
