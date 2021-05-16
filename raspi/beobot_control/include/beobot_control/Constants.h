//-----------------------------------------------------------------------------
// Colin's Header
// Author: Andrew Kramer
// 12/9/2016

// This header contains constants used in programs for Colin the robot
// including the nubers used for motor control pins and sensor pins

#ifndef Constants_h
#define Constants_h

//#include <bcm2835.h>
#include <stdint.h>
#include <stdio.h>


namespace beobot_control
{

#define channel_A   0x30
#define channel_B   0x34

#define DAC_Value_MAX  65535

#define DAC_VREF  3.3

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/**
 * GPIO config
**/
#define DEV_CS_PIN 23



/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value) bcm2835_gpio_write(_pin, _value)
#define DEV_Digital_Read(_pin) bcm2835_gpio_lev(_pin)

/**
 * SPI
**/
#define DEV_SPI_WriteByte(__value) bcm2835_spi_transfer(__value)
#define DEV_SPI_ReadByte() bcm2835_spi_transfer(0xff)
/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms) bcm2835_delay(__xms)

#define RH_PWM 6 // PWM pin for right hand motor
#define RH_BRAKE 37 // direction control for right hand motor BIN1 pin on motor controller
#define RH_REVERSE 35 // direction control for right hand motor BIN2 pin on motor controller

#define LH_PWM 5 // PWM pin for left hand motor
#define LH_BRAKE 36 // direction control for right hand motor AIN1 pin on motor controller
#define LH_REVERSE 34 // direction control for left hand motor AIN2 pin on motor controller


// pins for the RC inputs

#define THROTTLE 0
#define STEER 1
#define BRAKE 2
#define SWITCH 3
#define THROTTLESCALE 4
#define STEERSCALE 5


// gain values for PID motor control
// const double kP = 0.028, kI = 0.001, kD = 0.0006;

// delta T for speed calculation and PID adjustment
const long deltaT = 50000;

const int ticksPerRev = 45, wheelCirc = 76, wheelDist = 508;


//extern float value[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};


/*------------------------------------------------------------------------------------------------------*/

UBYTE DEV_ModuleInit(void);
void DEV_ModuleExit(void);
void DAC8532_Out_Voltage(UBYTE Channel, float Voltage);



}


#endif
