//-----------------------------------------------------------------------------
// Colin's Header
// Author: Andrew Kramer
// 12/9/2016

// This header contains constants used in programs for Colin the robot
// including the nubers used for motor control pins and sensor pins

#ifndef Constants_h
#define Constants_h



// delta T for speed calculation and PID adjustment
const long deltaT = 50000;


// pins for the RC inputs


#define HORIZONTAL 0
#define VERTICAL 1
#define SCALE 2
#define GEAR 3
#define REVERSE 4
#define SWITCH 5

#endif
