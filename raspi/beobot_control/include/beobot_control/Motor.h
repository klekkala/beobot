// Motor
// by Andrew Kramer

// controls direction and pwm input to a DC motor

#ifndef Motor_h
#define Motor_h

//#include "Motor.h"

namespace beobot_control
{
class Motor
{
public:
	Motor(int dir, int lbrake, int pwm);
	void setFwd();
	void setBack();
	void setBrake();
	void setStop();
	void setPWM(int level);
	void adjustPWM(float velocity);
  bool _forward, _neutral;
private:
	int _dir, _brake, _pwm;
};
}
#endif
