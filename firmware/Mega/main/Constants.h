//-----------------------------------------------------------------------------
// Colin's Header
// Author: Andrew Kramer
// 12/9/2016

// This header contains constants used in programs for Colin the robot
// including the nubers used for motor control pins and sensor pins

#ifndef Constants_h
#define Constants_h

#define TRUE 1
#define FALSE 0


// delta T for speed calculation
const long deltaT = 50000;

const int ticksPerRev = 600, wheelCirc = 76, wheelDist = 508;

// pins for the encoder inputs
#define RH_ENCODER_A 2
#define RH_ENCODER_B 3
#define LH_ENCODER_A 21
#define LH_ENCODER_B 20


// pins for the sonars
#define HORIZONTAL 0
#define VERTICAL 1
#define SCALE 2
#define STOP 4
#define SWITCH 5

#endif
