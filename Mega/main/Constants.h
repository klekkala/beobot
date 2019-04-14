//-----------------------------------------------------------------------------
// Colin's Header
// Author: Andrew Kramer
// 12/9/2016

// This header contains constants used in programs for Colin the robot
// including the nubers used for motor control pins and sensor pins

#ifndef Constants_h
#define Constants_h

#define RH_PWM 45 // PWM pin for right hand motor
#define RH_BRAKE 9 // direction control for right hand motor BIN1 pin on motor controller
#define RH_STOP 9 // direction control for right hand motor BIN1 pin on motor controller
#define RH_REVERSE 8 // direction control for right hand motor BIN2 pin on motor controller

#define LH_PWM 44 // PWM pin for left hand motor
#define LH_BRAKE 35 // direction control for right hand motor AIN1 pin on motor controller
#define LH_STOP 35 // direction control for right hand motor AIN1 pin on motor controller
#define LH_REVERSE 34 // direction control for left hand motor AIN2 pin on motor controller

// gain values for PID motor control
const double kP = 0.028, kI = 0.001, kD = 0.0006;

// delta T for speed calculation and PID adjustment
const long deltaT = 50000;

const int ticksPerRev = 45, wheelCirc = 76, wheelDist = 508;

// pins for the encoder inputs
#define RH_ENCODER_A 19
#define RH_ENCODER_B 20
#define RH_ENCODER_C 21
#define LH_ENCODER_A 2
#define LH_ENCODER_B 3
#define LH_ENCODER_C 18


// pins for the RC inputs


#define HORIZONTAL 0
#define VERTICAL 1
#define SCALE 2
#define STOP 4
#define SWITCH 5

#endif
