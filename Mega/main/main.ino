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
  digitalWrite(LH_BRAKE, HIGH);
  pinMode(LH_STOP, OUTPUT);
  digitalWrite(LH_STOP, HIGH);
  pinMode(LH_REVERSE, OUTPUT);
  digitalWrite(LH_REVERSE, HIGH);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH);
LeftMotor.setFwd();
  //Left Motor declarations
  pinMode(RH_PWM, OUTPUT);
  pinMode(RH_BRAKE, OUTPUT);
  digitalWrite(RH_BRAKE, HIGH);
  pinMode(RH_STOP, OUTPUT);
  digitalWrite(RH_STOP, HIGH);
  pinMode(RH_REVERSE, OUTPUT);
  digitalWrite(RH_REVERSE, HIGH);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH);

  /*noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
OCR1A = 31250;            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts*/
  //Serial writing
  Serial.begin(115200);
}


//Timer2 Overflow Interrupt Vector, called every 1ms
/*ISR(TIMER1_COMPA_vect){
  Serial.println("hidb");
}; */


 
void loop() {
  
  for(int i=0; i<6; i++){
    value[i] = pulseIn(channel[i], HIGH, 250000); // Read the pulse width of
  }

  //Serial.println(value[SWITCH]);
  //Some RC preprocessing
  float vertical = map(value[VERTICAL], 1000, 2000, -100, 100)/100;
  float horizontal = map(value[HORIZONTAL], 1000, 2000, 0, 100)/100;
  Serial.println("Start");
  
/*if (once == 1){
  
  
  LeftPositionControl.rotate(60, 15);
  once = 0;
}*/

//LeftEncoder.getSpeed();
//Serial.println(LeftEncoder.getDistance());
/*
  digitalWrite(LH_REVERSE, LOW);
  //digitalWrite(37, HIGH);
  delay(1000);
  analogWrite(LH_PWM, 200);
  delay(1000);
  analogWrite(LH_PWM, 0);
  digitalWrite(LH_REVERSE, HIGH);
  //digitalWrite(37, HIGH);
  delay(1000);
  */

  //Driver.drive(1, 0);
  //Drier.update();
  
  LeftMotor.setFwd();
  //LeftMotor.setPWM(180);
  //delay(4000);
  //LeftMotor.setStop();
  /*LeftMotor.setBack();
  delay(100);
  LeftMotor.setPWM(200);
  delay(1000);*/
    //digitalWrite(34, HIGH);
    //delay(1000);
    //analogWrite(44, 200);
    //delay(1000);
    //Serial.println("B");
    //Serial.println(counts.tickB);
    //Serial.println("C");
    //Serial.println(counts.tickC);
  
    
  //LeftEncoder.getSpeed();
  //LeftEncoder.getDistance();
     TickCounts counts = LeftEncoder.getCounts();
    Serial.println("A");
    Serial.println(counts.tickA);
    Serial.println("B");
    Serial.println(counts.tickB);
    Serial.println("C");
    Serial.println(counts.tickC);
   //delay(100);
  //LeftMotor.setPWM(0);
  //Serial.println(digitalRead(34));
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
  /*detachInterrupt(0);
  enc0_0 = 0;
  if(enc0_1 == 0)
    attachInterrupt(1, LeftupdateCountB, RISING);
  if(enc0_5 == 0)
    attachInterrupt(5, LeftupdateCountC, RISING);*/
  LeftEncoder.updateCountA();
  //LeftPositionControl.adjustPWM();

}

void LeftupdateCountB(){
  /*detachInterrupt(1);
  enc0_1 = 0;
  if(enc0_0 == 0)
    attachInterrupt(0, LeftupdateCountA, RISING);
  if(enc0_5 == 0)
    attachInterrupt(5, LeftupdateCountC, RISING);*/
  LeftEncoder.updateCountB();
  //LeftPositionControl.adjustPWM();
}

void LeftupdateCountC(){
  /*detachInterrupt(5);
  enc0_5 = 0;
  if(enc0_0 == 0)
    attachInterrupt(0, LeftupdateCountA, RISING);
  if(enc0_1 == 0)
    attachInterrupt(1, LeftupdateCountB, RISING);*/
  LeftEncoder.updateCountC();
  //LeftPositionControl.adjustPWM();
}

void RightupdateCountA(){
  detachInterrupt(2);
  RightEncoder.updateCountA();
  attachInterrupt(3, RightupdateCountB, RISING);
  attachInterrupt(4, RightupdateCountC, RISING);
}

void RightupdateCountB(){
  detachInterrupt(3);
  RightEncoder.updateCountA();
  attachInterrupt(2, RightupdateCountA, RISING);
  attachInterrupt(4, RightupdateCountC, RISING);
}

void RightupdateCountC(){
  detachInterrupt(4);
  RightEncoder.updateCountA();
  attachInterrupt(2, RightupdateCountA, RISING);
  attachInterrupt(3, RightupdateCountB, RISING);
}
