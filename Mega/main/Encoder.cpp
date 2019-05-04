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
  _encoderC = encoderC;
  _marker = 0;
  _oldCount = 0;
  _newCount = 0;
  _totalCount = 0;
  _lastSpeed = 0;
  _deltaT = deltaT;
  _degPerTick = 360.0 / (double)ticksPerRev;
  _deltaT = deltaT;
  _rawCounts.tickA = 0;
  _rawCounts.tickB = 0;
  _rawCounts.tickC = 0;
  _oldtime = 0;
}

// returns the average speed of the motor output shaft in degrees/second
// over the last _deltaT microseconds
// MUST be called every _deltaT microseconds to return accurate speed
int Encoder::getSpeed(bool forward)
{
  /*if(forward == 1){
    _count = min(_rawCounts.tickA, min(_rawCounts.tickB, _rawCounts.tickC));
   _rawCounts.tickA = _count;
  _rawCounts.tickB = _count;
  _rawCounts.tickC = _count;
  }
  else{
    _count = max(_rawCounts.tickA, max(_rawCounts.tickB, _rawCounts.tickC));
   _rawCounts.tickA = _count;
  _rawCounts.tickB = _count;
  _rawCounts.tickC = _count;
  }*/
  
  _oldCount = _newCount;
  _newCount = _count;
  // calculate number of ticks elapsed since in last deltaT
 //Serial.println("infunc");
  int difference = _newCount - _oldCount;
  
  // update _totalCount
  _totalCount += difference;
  int degPerSec;
  // calculate new speed if _count has not overflowed 
  if (difference < 50000 && difference > -50000)
  {
    double deltaTInSec = 1000.00/(double)(millis()-_oldtime);
    double ticksPerSec = (double)difference * (double)deltaTInSec;
    //Serial.println(deltaTInSec);
    //Serial.println(difference);
    degPerSec = ticksPerSec * _degPerTick;
    _lastSpeed = degPerSec;
  }
  else // use previous speed if overflow has occurred in _count
  {
    degPerSec = _lastSpeed;
  }
  Serial.println("real speed");
  Serial.println(degPerSec);
  _oldtime = millis();
  return degPerSec;
}

// returns net distance rotated by the motor's output shaft in degrees
// since the last call to getDistance()
// should be called regularly to prevent overflows in _totalCount
int Encoder::getDistance()
{
  int distance = _degPerTick * _totalCount;
  _totalCount = 0;
  return distance;
}

// Atomically read both counts.
TickCounts Encoder::getCounts()
{
    TickCounts counts;
    noInterrupts();
    counts.tickA = _rawCounts.tickA;
    counts.tickB = _rawCounts.tickB;
    counts.tickC = _rawCounts.tickC;
    interrupts();
    return counts;
}

// updates the _count when an encoder event occurs
// must be called using a pin change interrupt from the client sketch
void Encoder::updateCountA(bool forward)
{
  int0diff = micros() - int0time;
  if ( int0diff < threshold )
    return;
  else{
      //Serial.println("A");
    //Serial.println(int0diff);
    //Serial.println(_marker);
  if(forward == 1){
    _rawCounts.tickA++;
    _count++;
  }
  else{
    _rawCounts.tickA--;
    _count--;
  }
  int0time = micros();
}
}

// updates the _count when an encoder event occurs
// must be called using a pin change interrupt from the client sketch
void Encoder::updateCountB(bool forward)
{
  int1diff = micros() - int1time;
  if ( int1diff < threshold )
    return;
  else{
    //Serial.println("B");
    //Serial.println(int1diff);
    //Serial.println(_marker);
  if(forward == 1){
    _rawCounts.tickB++;
    _count++;
  }
  else{
    _rawCounts.tickB--;
    _count--;
  }
  int1time = micros();
}
}

// updates the _count when an encoder event occurs
// must be called using a pin change interrupt from the client sketch
void Encoder::updateCountC(bool forward)
{
  int2diff = micros() - int2time;
  if ( int2diff < threshold )
    return;
  else{
      //Serial.println("C");
    //Serial.println(int2diff);
        //Serial.println(_marker);
  if(forward == 1){
    _rawCounts.tickC++;
    _count++;
  }
  else{
    _rawCounts.tickC--;
    _count--;
  }
  int2time = micros();
  }
}
