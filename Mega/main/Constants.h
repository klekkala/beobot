//-----------------------------------------------------------------------------
// Colin's Header
// Author: Andrew Kramer
// 12/9/2016

// This header contains constants used in programs for Colin the robot
// including the nubers used for motor control pins and sensor pins

#ifndef Constants_h
#define Constants_h

#define RH_PWM 6 // PWM pin for right hand motor
#define RH_BRAKE 9 // direction control for right hand motor BIN1 pin on motor controller
#define RH_STOP 9 // direction control for right hand motor BIN1 pin on motor controller
#define RH_REVERSE 8 // direction control for right hand motor BIN2 pin on motor controller

#define LH_PWM 11 // PWM pin for left hand motor
#define LH_BRAKE 13 // direction control for right hand motor AIN1 pin on motor controller
#define LH_STOP 13 // direction control for right hand motor AIN1 pin on motor controller
#define LH_REVERSE 12 // direction control for left hand motor AIN2 pin on motor controller

// gain values for PID motor control
const double kP = 0.028, kI = 0.001, kD = 0.0006;

// delta T for speed calculation and PID adjustment
const long deltaT = 50000;

const int ticksPerRev = 309, wheelCirc = 189, wheelDist = 100;

// pins for the encoder inputs
#define RH_ENCODER_A 3 
#define RH_ENCODER_B 5
#define RH_ENCODER_C 5
#define LH_ENCODER_A 2
#define LH_ENCODER_B 4
#define LH_ENCODER_C 2


// pins for the RC inputs
#define VERTICAL 40
#define HORIZONTAL 41
#define SCALE 42
#define REVERSE 43
#define STOP 44
#define SAFE 45

#endif