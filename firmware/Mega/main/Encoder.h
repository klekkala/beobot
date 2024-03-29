// Encoder
// by Andrew Kramer

// initializes an object to read input from a shaft encoder and
// track the number of encoder ticks using interrupts
// only works with Arduino Uno, Duemilanove, and others that
// have interrupt 0 defined as digital pin 2 and interrupt 1
// defined as digital pin 3

#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

   struct TickCounts {
    long tickA;
    long tickB;
};

class Encoder
{
public:

  Encoder(int encoderA, int encoderB, int encoderC, 
      long deltaT, int ticksPerRev);
  int getSpeed(bool forward); // returns speed in degrees per second
  int getDistance(); // returns distance rotated in degrees
  TickCounts getCounts();
  void updateCountA(bool forward);
  void updateCountB(bool forward);
  void updateCountC(bool forward);
  volatile unsigned long int0time = 0;
  volatile unsigned long int1time = 0;
  volatile unsigned long int2time = 0;
  volatile unsigned long int0diff = 0;
  volatile unsigned long int1diff = 0;
  volatile unsigned long int2diff = 0;
  volatile unsigned long threshold = 12500;



  //volatile TickCounts rawCounts;
private:
  int _encoderA, _encoderB, _encoderC, _marker; // encoder pins
  double _degPerTick; // degrees of output shaft rotation per encoder tick
  volatile long _count, _oldCount, _newCount;
  long _deltaT; // in microseconds
  int _lastSpeed;
  volatile long _totalCount;
  long _oldtime;
  TickCounts _rawCounts;
};

#endif
