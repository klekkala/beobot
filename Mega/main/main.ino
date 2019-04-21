//License information

#include "Constants.h"
#include "DifferentialDrive.h"
#include "Encoder.h"
#include "Motor.h"
#include "PositionControl.h"
#include "SpeedControl.h"

const uint32_t PRINT_PERIOD = 1e6;  // print counts every second


Motor LeftMotor = Motor(LH_REVERSE, LH_STOP, LH_BRAKE, LH_PWM);
Motor RightMotor = Motor(RH_REVERSE, RH_STOP, RH_BRAKE, RH_PWM);

Encoder LeftEncoder = Encoder(LH_ENCODER_B, LH_ENCODER_C, LH_ENCODER_A, deltaT, ticksPerRev);
Encoder RightEncoder = Encoder(RH_ENCODER_A, RH_ENCODER_C, RH_ENCODER_B, deltaT, ticksPerRev);

SpeedControl LeftSpeedControl = SpeedControl(&LeftMotor, &LeftEncoder);
SpeedControl RightSpeedControl = SpeedControl(&RightMotor, &RightEncoder);

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

  LeftSpeedControl.setGains(kP, kI, kD);
  RightSpeedControl.setGains(kP, kI, kD);
  //Left Encoder declarations
  pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(LH_ENCODER_C, INPUT);
  attachInterrupt(0, LeftupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(1, LeftupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(5, LeftupdateCountC, RISING);//Initialize the interrupt pin

  //Right Encoder declarations
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_C, INPUT);
  attachInterrupt(2, RightupdateCountA, RISING);//Initialize the interrupt pin
  attachInterrupt(3, RightupdateCountB, RISING);//Initialize the interrupt pin
  attachInterrupt(4, RightupdateCountC, RISING);//Initialize the interrupt pin


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

  noInterrupts();           // disable all interrupts
  /*TCCR2A = 0;     // set entire TCCR3A register to 0
  TCCR2B = 0;     // same for TCCR3B
  TCNT2  = 1000;
  OCR2A = 2000;
  TCCR2B |= (1 << WGM22);
  TCCR2B |= (1 << CS22);
  TIMSK2 |= (1 << OCIE2A);*/
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 1500;            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << 0x02);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  
  TCCR3A = 0;     // set entire TCCR3A register to 0
  TCCR3B = 0;     // same for TCCR3B
  TCNT3  = 3500;
  OCR3A = 5000;
  TCCR3B |= (1 << WGM32);
  // Set CS10 and CS12 bits for 1024 prescaler:
  TCCR3B |= (1 << 0x02);
  // enable timer compare interrupt:
  TIMSK3 |= (1 << OCIE3A);

  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4  = 7500;
  OCR4A = 9000;            // compare match register 16MHz/256/2Hz
  TCCR4B |= (1 << WGM42);   // CTC mode
  TCCR4B |= (1 << 0x02);    // 256 prescaler 
  TIMSK4 |= (1 << OCIE4A);  // enable timer compare interrupt*/
  
  interrupts();             // enable all interrupts
  //Serial writing
  Serial.begin(115200);

}

/*
//Timer2 Overflow Interrupt Vector, called every 1ms
ISR(TIMER2_OVF_vect){
  //LeftEncoder.getSpeed(LeftMotor._forward);
  //Serial.println("timer");
    
    //LeftSpeedControl.adjustPWM();
    //RightSpeedControl.adjustPWM();
   //Driver.update();
   Serial.println("HELLO");
        TCNT2 = 1;           //Reset Timer to 130 out of 255
  TIFR2 = 0x00;          //Timer2 INT Flag Reg: Clear Timer Overflow Flag

};*/


//Timer2 Overflow Interrupt Vector, called every 1ms
ISR(TIMER1_COMPA_vect){
  value[VERTICAL] = pulseIn(channel[VERTICAL], HIGH, 50000); // Read the pulse width of
  Serial.println(value[VERTICAL]);
  //Serial.println("hello");
  TCNT1  = 0;

};

//Timer2 Overflow Interrupt Vector, called every 1ms
ISR(TIMER3_COMPA_vect){
  value[HORIZONTAL] = pulseIn(channel[HORIZONTAL], HIGH, 50000); // Read the pulse width of
  Serial.println(value[HORIZONTAL]);
  TCNT3  = 3500;

};

//Timer2 Overflow Interrupt Vector, called every 1ms
ISR(TIMER4_COMPA_vect){
  value[SWITCH] = pulseIn(channel[SWITCH], HIGH, 50000); // Read the pulse width of
  Serial.println(value[SWITCH]);
  TCNT4  = 7500;

};

void loop() {
  
//Serial.println("loosdfsdfasdfas");
    
  //Driver.drive(scale*vertical/100, scale*horizontal/100);
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
  //LeftMotor.setFwd();
  //LeftMotor.setPWM(75);
  //LeftSpeedControl.setSpeed(0);
  //delay(1000000);
  //RightSpeedControl.setSpeed(360);
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

    /*LeftMotor.setBack();
    LeftMotor.setPWM(180);
    delay(415);
    LeftMotor.setPWM(0);
    delay(4000);
        counts = LeftEncoder.getCounts();
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
  /*detachInterrupt(5);
  enc0_5 = 0;
  if(enc0_0 == 0)
    attachInterrupt(0, LeftupdateCountA, RISING);
  if(enc0_1 == 0)
    attachInterrupt(1, LeftupdateCountB, RISING);*/
  /*if (digitalRead(18) == HIGH)
    LeftEncoder.updateCountC_up();
  else{
    LeftEncoder.updateCountC();
  }*/
  LeftEncoder.updateCountA(LeftMotor._forward);
}

void LeftupdateCountB(){
  /*detachInterrupt(5);
  enc0_5 = 0;
  if(enc0_0 == 0)
    attachInterrupt(0, LeftupdateCountA, RISING);
  if(enc0_1 == 0)
    attachInterrupt(1, LeftupdateCountB, RISING);*/
  /*if (digitalRead(18) == HIGH)
    LeftEncoder.updateCountC_up();
  else{
    LeftEncoder.updateCountC();
  }*/
  LeftEncoder.updateCountB(LeftMotor._forward);
}

void LeftupdateCountC(){
  /*detachInterrupt(5);
  enc0_5 = 0;
  if(enc0_0 == 0)
    attachInterrupt(0, LeftupdateCountA, RISING);
  if(enc0_1 == 0)
    attachInterrupt(1, LeftupdateCountB, RISING);*/
  /*if (digitalRead(18) == HIGH)
    LeftEncoder.updateCountC_up();
  else{
    LeftEncoder.updateCountC();
  }*/
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
