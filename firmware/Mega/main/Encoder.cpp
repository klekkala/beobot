// Encoder
// by Andrew Kramer

// initializes an object to read input from a shaft encoder and
// track the number of encoder ticks using interrupts

#include "Encoder.h"
#include "Arduino.h"

// accepts three ints and a long as parameters:
//      encoderA - the digital pin used to read encoder output A
//                 this MUST be an interrupt pin
//      encoderB - the digital pin used to read encoder output B
//        deltaT - the time interval used to calculate output shaft speed
//                 in microseconds
//   ticksPerRev - the number of encoder ticks per revolution of 
//                 the output shaft
Encoder::Encoder(int encoderA, int encoderB, int encoderC, 
         long deltaT, int ticksPerRev)
{
  _encoderA = encoderA;
  _encoderB = encoderB;
  _marker = 0;
  _oldCount = 0;
  _newCount = 0;
  _totalCount = 0;
  _lastSpeed = 0;
  _deltaT = deltaT;
  _degPerTick = 360.0 / (double)ticksPerRev;
  _deltaT = deltaT;
  _rawCount = 0;
  _oldtime = 0;
}

// returns the average speed of the motor output shaft in degrees/second
// over the last _deltaT microseconds
// MUST be called every _deltaT microseconds to return accurate speed
// _deltaT microseconds refer to the void loop cycle
int Encoder::getSpeed()
{
  _oldCount = _newCount;
  _newCount = _rawCount;
  // calculate number of ticks elapsed since in last deltaT
  
  int difference = _newCount - _oldCount;
  // update _totalCount
  // _totalCount
  _totalCount += difference;
  
  int degPerSec;

  // calculate new speed if _rawCount has not overflowed
  // which probably would never happen because we call it so many times
  if (difference < 50000 && difference > -50000)
  {
    double deltaTInSec = 1000.00/(double)(millis()-_oldtime);
    double ticksPerSec = (double)difference * (double)deltaTInSec;

    degPerSec = ticksPerSec * _degPerTick;
    _lastSpeed = degPerSec;
  }
  else // use previous speed if overflow has occurred in _rawCount
  {
    degPerSec = _lastSpeed;
  }

  _oldtime = millis();
  return degPerSec;
}


// returns net distance rotated by the motor's output shaft in degrees
// since the last call to getDistance()
// should be called regularly to prevent overflows in _totalCount
// _totalCount is the actual variable which keeps track of the distance
// but this would'nt overflow mostly because it's reset every time
// we call it.
int Encoder::getDistance()
{
  int distance = _degPerTick * _totalCount;
  _totalCount = 0;
  return distance;
}

// Atomically read both counts.
TickCounts Encoder::getCounts()
{
    //noInterrupts();
    counts = _rawCount;
    //interrupts();
    return counts;
}

// updates the _rawCount when an encoder event occurs
// must be called using a pin change interrupt from the client sketch
void Encoder::updateCountA(bool forward)
{
  if(forward == TRUE){
    _rawCount++;
  }
  else{
    _rawCount--;
  }
}

// updates the _rawCount when an encoder event occurs
// must be called using a pin change interrupt from the client sketch
void Encoder::updateCountB(bool forward)
{
  if(forward == TRUE){
    _rawCount--;
  }
  else{
    _rawCount++;
  }
}
