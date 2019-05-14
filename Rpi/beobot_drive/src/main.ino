//License information

#include "Constants.h"
#include "DifferentialDrive.h"
#include "Encoder.h"
#include "Motor.h"
#include "PositionControl.h"
#include "SpeedControl.h"
#include <Wire.h>
#include "Adafruit_MCP4725.h"
//MCP4725 library
Adafruit_MCP4725 dac;
const uint32_t PRINT_PERIOD = 1e6;  // print counts every second


Motor LeftMotor = Motor(LH_REVERSE, LH_STOP, LH_BRAKE, LH_PWM);
Motor RightMotor = Motor(RH_REVERSE, RH_STOP, RH_BRAKE, RH_PWM);

Encoder LeftEncoder = Encoder(LH_ENCODER_B, LH_ENCODER_C, LH_ENCODER_A, deltaT, ticksPerRev);
Encoder RightEncoder = Encoder(RH_ENCODER_A, RH_ENCODER_C, RH_ENCODER_B, deltaT, ticksPerRev);

SpeedControl LeftSpeedControl = SpeedControl(&LeftMotor, &LeftEncoder, 70);
SpeedControl RightSpeedControl = SpeedControl(&RightMotor, &RightEncoder, 164);

//LeftSpeedControl.setGains(kP, kI, kD);
//RightSpeedControl.setGains(kP, kI, kD);

PositionControl LeftPositionControl = PositionControl(&LeftSpeedControl);
PositionControl RightPositionControl = PositionControl(&RightSpeedControl);


DifferentialDrive Driver = DifferentialDrive(&LeftPositionControl, &RightPositionControl, wheelCirc, wheelCirc);
TickCounts counts;
//Loop scope variables
int channel[6] = {28, 29, 30, 31, 32, 33};
float value[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

bool enc0_0 = 1;
bool enc0_1 = 1;
bool enc0_5 = 1;

bool once = 1;
void setup() {

  LeftSpeedControl.setGains(0.004, 0, 0.005);
  RightSpeedControl.setGains(0.009, 0, 0.005);
  //Left Encoder declarations
  /*pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(LH_ENCODER_C, INPUT);
  attachInterrupt(0, LeftupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(1, LeftupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(5, LeftupdateCountC, RISING);//Initialize the interrupt pin*/

  //Right Encoder declarations
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_C, INPUT);
  attachInterrupt(0, RightupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(1, RightupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(5, RightupdateCountC, RISING);//Initialize the interrupt pin


  //RC declarations
  pinMode(VERTICAL, INPUT);
  pinMode(HORIZONTAL, INPUT);
  pinMode(SCALE, INPUT);
  pinMode(STOP, INPUT);
  pinMode(SWITCH, INPUT);
  
  //Left Motor declarations
  pinMode(LH_PWM, OUTPUT);
  pinMode(LH_BRAKE, OUTPUT);
  //digitalWrite(LH_BRAKE, HIGH);
  //pinMode(LH_STOP, OUTPUT);
  //digitalWrite(LH_STOP, HIGH);
  pinMode(LH_REVERSE, OUTPUT);
  //digitalWrite(LH_REVERSE, HIGH);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH);
  
  //Left Motor declarations
  pinMode(RH_PWM, OUTPUT);
  pinMode(RH_BRAKE, OUTPUT);
  //digitalWrite(RH_BRAKE, HIGH);
  //pinMode(RH_STOP, OUTPUT);
  //digitalWrite(RH_STOP, HIGH);
  pinMode(RH_REVERSE, OUTPUT);
  //digitalWrite(RH_REVERSE, HIGH);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH);
dac.begin(0x60);
  noInterrupts();           // disable all interrupts


  
  /*TCCR2A = 0;     // set entire TCCR3A register to 0
  TCCR2B = 0;     // same for TCCR3B
  TCNT2  = 0;
  OCR2A = 0;
  TCCR2B |= (1 << WGM22);
  TCCR2B |= (1 << CS22);
  TIMSK2 |= (1 << OCIE2A);
  
  TCCR3A = 0;     // set entire TCCR3A register to 0
  TCCR3B = 0;     // same for TCCR3B
  TCNT3  = 0;
  OCR3A = 1500;
  TCCR3B |= (1 << WGM32);
  // Set CS10 and CS12 bits for 1024 prescaler:
  TCCR3B |= (1 << CS32);
  // enable timer compare interrupt:
  TIMSK3 |= (1 << OCIE3A);

  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4  = 0;
  OCR4A = 1500;            // compare match register 16MHz/256/2Hz
  TCCR4B |= (1 << WGM42);   // CTC mode
  TCCR4B |= (1 << CS42);    // 256 prescaler 
  TIMSK4 |= (1 << OCIE4A);  // enable timer compare interrupt*/
  
  interrupts();             // enable all interrupts
  //Serial writing
  Serial.begin(115200);

}

//Timer2 Overflow Interrupt Vector, called every 1ms
/*ISR(TIMER2_COMPA_vect){
  /*value[SWITCH] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  value[SWITCH] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  value[SWITCH] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  value[SWITCH] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of*/
  /*if(value[SWITCH] <1200)
    LKSJDFKL;
  else if(value[SWITCH] == 23){
    LSKDJFKLJ;
  }
  else if(value[SWITCH] ==34){
    SDFSADF;
  }
   value[HORIZONTAL] = pulseIn(channel[HORIZONTAL], HIGH, 25000); // Read the pulse width of
   value[VERTICAL] = pulseIn(channel[VERTICAL], HIGH, 25000); // Read the pulse width of
  value[STOP] = pulseIn(channel[STOP], HIGH, 25000); // Read the pulse width of
  //value[SWITCH] = pulseIn(channel[SWITCH], HIGH, 50000); // Read the pulse width of
  //value[SCALE] = pulseIn(channel[SCALE], HIGH, 50000); // Read the pulse width of
  //RightSpeedControl.setSpeed(1000);

  //float scale = map(value[SCALE], 990, 2000, 0, 100);
  //float horizontal = map(value[HORIZONTAL], 990, 2000, 0, 100);
  //float vertical = map(value[VERTICAL], 990, 2000, 0, 100);
  //Serial.println("hi");
  //LeftSpeedControl.adjustPWM();
  //RightSpeedControl.adjustPWM();
  //Driver.update();
  TCNT2  = 0;

};*/

bool back = false;

//Timer2 Overflow Interrupt Vector, called every 1ms
/*ISR(TIMER1_COMPA_vect){

  //Serial.println("hi");
  //LeftSpeedControl.adjustPWM();
  //RightSpeedControl.adjustPWM();
  //Driver.update();
  TCNT1  = 0;

};*/
void loop() {
    /*value[HORIZONTAL] = pulseIn(channel[HORIZONTAL], HIGH, 50000); // Read the pulse width of
  value[VERTICAL] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  value[STOP] = pulseIn(channel[STOP], HIGH, 50000); // Read the pulse width of
  value[SWITCH] = pulseIn(channel[SWITCH], HIGH, 50000); // Read the pulse width of
  value[SCALE] = pulseIn(channel[SCALE], HIGH, 50000); // Read the pulse width of
  //RightSpeedControl.setSpeed(1000);


  if (value[HORIZONTAL] == 0.0 or value[VERTICAL] == 0.0 or value[SCALE] == 0.0 or value[SWITCH] == 0.0){
    delay(1000);
  }
  else{
  float scale = map(value[SCALE], 990, 2000, 0, 150);
  float horizontal = map(value[HORIZONTAL], 990, 2000, -5, 5);
  float vertical = map(value[VERTICAL], 990, 2000, 0, 100);

 if (horizontal < 2 and horizontal > -2)
  horizontal = 0;
 else if (horizontal < -2){
  horizontal = horizontal + 2;
 }

  else if(horizontal > 2){
  horizontal = horizontal - 2;
 }
  //RightSpeedControl.setSpeed(720);
  //Serial.println(testkp*0.001);
  //Serial.println("loop");
  if (value[STOP] < 1500)
    back = true;
  else
    back = false;

    //Serial.println(scale*vertical/100);
  //LeftSpeedControl.setSpeed(1000);
  //RightSpeedControl.setSpeed(1000);
  //LeftSpeedControl.adjustPWM();
  //RightSpeedControl.adjustPWM();
  Driver.drive(scale*vertical/100, horizontal, back);
  Driver.update();
  if (value[SWITCH] > 1500){
    LeftMotor.setStop();
    RightMotor.setStop();
  }
  }*/
 /*if (value[SWITCH] > 1500)
    Driver.drive(0, 0);
  else{
    Serial.println("scalevertical");
    int currvalue = value[SCALE]/10-100;
    if(currvalue < 15){
      currvalue = 15;
    }
    Serial.println(currvalue);
    Driver.drive(currvalue, 0);
  }*/
  //value[SCALE] = pulseIn(channel[SCALE], HIGH, 50000);
  RightMotor.setFwd();
  for(int i=1100; i< 1201;i++){
    //loat scale = map(value[SCALE], 990, 2000,  , 255);
    Serial.println(i);
    dac.setVoltage(i, false);
    RightEncoder.getSpeed(RightMotor._forward);
    delay(400);
  }
  //LeftMotor.setPWM(scale);
  /*for(int j=60; kj<110; j++){
    Serial.println("start of pwm");
    Serial.println(j);
    LeftMotor.setPWM(j);
    delay(2000);
    Serial.println("left");
    LeftEncoder.getSpeed(LeftMotor._forward);
    LeftEncoder.getDistance();
    
    RightMotor.setPWM(j);
    delay(2000);
    Serial.println("right");
    RightEncoder.getSpeed(RightMotor._forward);
    RightEncoder.getDistance();
  }*/
    /*LeftMotor.setPWM(76);
    delay(1000);
    Serial.println("left");
    LeftEncoder.getSpeed(LeftMotor._forward);
    LeftEncoder.getDistance();
    
    RightMotor.setPWM(169);
    delay(1000);
    Serial.println("right");
    RightEncoder.getSpeed(RightMotor._forward);
    RightEncoder.getDistance();*/
    
  //LeftSpeedControl.setSpeed(16);
  //delay(1000000);
  //RightSpeedControl.setSpeed(160);
//delay(100000000);

  //Driver.drive(1, 0);
  //Drier.update();

  //LeftMotor.setFwd();
  //LeftMotor.setPWM(100);
//Test for motors
  /*//RightMotor.setBack();
  LeftMotor.setFwd();
  //RightMotor.setPWM(150);
  LeftMotor.setPWM(130);
  delay(415);
  LeftMotor.setPWM(0);*/
  //delay(4000);
    /*counts = LeftEncoder.getCounts();
    Serial.println("A");
    Serial.println(counts.tickA);
    Serial.println("B");
    Serial.println(counts.tickB);
    Serial.println("C");
    Serial.println(counts.tickC);*/

    /*RightMotor.setBack();
    RightMotor.setPWM(180);
    //delay(415);
    //LeftMotor.setPWM(0);
    //delay(4000);
    counts = RightEncoder.getCounts();
    Serial.println("A");
    Serial.println(counts.tickA);
    Serial.println("B");
    Serial.println(counts.tickB);
    Serial.println("C");
    Serial.println(counts.tickC);
    delay(100000000);*/
    //Serial.println(LeftEncoder.getDistance());
   //delay(100);*/
     /*counts = LeftEncoder.getCounts();
    Serial.println("A");
    Serial.println(counts.tickA);
    Serial.println("B");
    Serial.println(counts.tickB);
    Serial.println("C");
    Serial.println(counts.tickC);*/
  /*
  if (value[SWITCH] > 1000){
    Serial.println(vertical);
    LeftMotor.setPWM(0);
    Driver.drive(vertical, horizontal);
  }

  else{
    //Serial.read()
    Serial.println("hello");
  }
  */
}

void LeftupdateCountA(){
  LeftEncoder.updateCountA(LeftMotor._forward);
}

void LeftupdateCountB(){
  LeftEncoder.updateCountB(LeftMotor._forward);
}

void LeftupdateCountC(){
  LeftEncoder.updateCountC(LeftMotor._forward);
}


void RightupdateCountA(){
  RightEncoder.updateCountA(RightMotor._forward);
}

void RightupdateCountB(){
  RightEncoder.updateCountB(RightMotor._forward);
}

void RightupdateCountC(){
  RightEncoder.updateCountC(RightMotor._forward);
}
