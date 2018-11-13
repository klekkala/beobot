#define DDRIVE_MIN -100 //The minimum value x or y can be.
#define DDRIVE_MAX 100  //The maximum value x or y can be.
#define MOTOR_MIN_PWM -255 //The minimum value the motor output can be.
#define MOTOR_MAX_PWM 255 //The maximum value the motor output can be.

int LeftMotorOutput; //will hold the calculated output for the left motor
int RightMotorOutput; //will hold the calculated output for the right motor



void DifferentialDriveService::CalculateTankDrive(float x, float y)
{
 float rawLeft;
 float rawRight;
 float RawLeft;
 float RawRight;


 // first Compute the angle in deg
 // First hypotenuse
 float z = sqrt(x * x + y * y);

// angle in radians
 float rad = acos(abs(x) / z);

// Cataer for NaN values
 if (isnan(rad) == true) {
 rad = 0;
 }

// and in degrees
 float angle = rad * 180 / PI;

// Now angle indicates the measure of turn
 // Along a straight line, with an angle o, the turn co-efficient is same
 // this applies for angles between 0-90, with angle 0 the co-eff is -1
 // with angle 45, the co-efficient is 0 and with angle 90, it is 1

float tcoeff = -1 + (angle / 90) * 2;
 float turn = tcoeff * abs(abs(y) - abs(x));
 turn = round(turn * 100) / 100;

// And max of y or x is the movement
 float mov = max(abs(y), abs(x));

// First and third quadrant
 if ((x >= 0 && y >= 0) || (x < 0 && y < 0))
 {
 rawLeft = mov; rawRight = turn;
 }
 else
 {
 rawRight = mov; rawLeft = turn;
 }

// Reverse polarity
 if (y < 0) {
 digitalWrite(relay, HIGH);
 }

// Update the values
 RawLeft = rawLeft;
 RawRight = rawRight;


 Serial.println(RawLeft)
 Serial.println(RawRight)
// Map the values onto the defined rang
 LeftMotorOutput = map(rawLeft, DDRIVE_MIN, DDRIVE_MAX, MOTOR_MIN_PWM, MOTOR_MAX_PWM);
 RightMotorOutput = map(rawRight, DDRIVE_MIN, DDRIVE_MAX, MOTOR_MIN_PWM, MOTOR_MAX_PWM);
}



//Sender Code
//#include "RCrecieve.h"


void setup() {
  //rcsetup();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM20);
  //TCCR2B = _BV(WGM22) | _BV(CS22);
  //OCR2A = 250;
  //OCR2B = 250;

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  
  
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  pinMode(12, OUTPUT);

  //Serial writing
  Serial.begin(115200);
}

void loop() {
  int i;
  float lp,rp;
  
  float a = pulseIn(2, HIGH, 250000); // Read the pulse width of
  float b = pulseIn(3, HIGH, 250000); // Read the pulse width of
  float c = pulseIn(4, HIGH, 250000); // Read the pulse width of
  float d = pulseIn(7, HIGH, 250000); // Read the pulse width of
  float ver = ((c-1000)/1000)*255;
  float hor = ((b-1000)/1000)*255;
  float scaler = a;
  float reverse = d;

  //c is right vertical
  //a is left vertical
  //b is right horizontal
  //d is reverse or forward switch


if (ver <=1500 && digitalRead(reverse) == HIGH){
     digitalWrite(relay, LOW);
  }

  else{
    CalculateTankDrive(hor, ver)
  }
  //digitalWrite(10,LOW);
  //digitalWrite(11,HIGH);
  //delay(100);
}
