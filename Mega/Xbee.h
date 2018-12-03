/*
# The library for the URM04 sketch

# Editor : Lauren
# Date   : 2012.2.8
# Ver    : 0.3
# Product: URM04 Ultrasonic sensor

# Specification
    * Detecting range: 4cm-500cm
    * Resolution     : 1cm
    * Interface      : RS485
    * Units: Range reported in cm
    * Temperature sensor: 12 bits reading from serial port
    

# Description:

# finish driving single URM function
# if use the IO expansion shield to drive the urm sensors, the measuring rate may be 20Hz or slower[if you want].
# The sample code is compatible with the Arduino IDE 1.0 and also the earlier version.

*/
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#define printByte(args) Serial.write(args)
#else
#include "WProgram.h"
#define printByte(args) Serial.print(args,BYTE)
#endif

#define SerialPort Serial
#define urmAccount 1   // Init the account of the URM04 sensor
#define CommMAXRetry 40
#define TriggerPin 2

/******************** Variables ****************/

byte startAddr = 0x11; // Init the URM04 485 Address -- URM04 default address = 0x11

byte readingStep;
byte cmdst[10];
int urmID[urmAccount];
unsigned int urmData[urmAccount];
unsigned long managerTimer = 20;

/******************** Functions ****************/
void urmInit();
void runUrm4();
void urmTrigger(int id);
void urmReader(int id);
void transmitCommands();
void decodeURM4();
void analyzeUrmData(byte cmd[]);

/****************** Init sensor ****************/

void urmInit(){
  
  pinMode(TriggerPin,OUTPUT);  // TTL -> RS485 chip driver pin
  digitalWrite(TriggerPin,LOW);// Turn the driver pin to LOW  -> Turn on reading mode for the RS485 interface
                               // Turn the drvier pin to HIGH -> Turn on code transmitting mode for the RS485 interface
  readingStep = 0;
  startAddr = 0x11;
  managerTimer = millis();
  for(int i = 0 ;i < urmAccount; i ++){  //Init the URM04 command receiving address
    urmID[i] = startAddr + i;
    urmData[i] = 0;
  }
  SerialPort.begin(19200);               // Init the RS485 interface
                                         // Also when you are driving the URM04, you could open serial monitor to 
                                         // tracing the steps and data feedback from URM04
  SerialPort.println();
  SerialPort.print("The URM ID: 0x");
  for(int i = 0 ;i < urmAccount; i ++){  //Init the URM04 command receiving address
    SerialPort.print(urmID[i],HEX);
    SerialPort.print(" ");
  }
  SerialPort.println(" ");
  SerialPort.println("The default baudrate: 19200");
  SerialPort.println("Start drive the sensors!");
  for(int i = 0 ;i < 10; i++)  cmdst[i] = 0;  //init the URM04 protocol
  cmdst[0]=0x55;  
  cmdst[1]=0xaa;
}

/********************* Drive URM04 and get the data code *************************/

void runUrm4(){                 // You could adjust the sensor measuring rate by changing the managerTimer value

  static unsigned long timer = 0;
  static int num = 0;           //Set the URM04 id to be drived
  
  if(millis() - timer > managerTimer){
    digitalWrite(TriggerPin, HIGH);  //Turn on transmitting mode for the RS485 interface
    
    switch(readingStep){

    case 0:
      urmTrigger(urmID[num]);
      managerTimer = 40;            //set a interval after trigger the measuring
      
      break;

    case 1:
      urmReader(urmID[num]);
      managerTimer = 0;             //set a interval after transmitting the reading distance command
 
      break;

    case 2:
      digitalWrite(TriggerPin, LOW); //Turn on reading mode for the RS485 interface
      managerTimer = 10;
      break;
      
    default:
      readingStep = 0;               // Finish reading the distance and start a new measuring for the sensor
      break;
    }
    
    if(readingStep < 2)  readingStep++;  //step manager
    else readingStep = 0;

    timer = millis();
  }

}

/********************* Transmit Command via the RS485 interface ***************/

void urmTrigger(int id){  // The function is used to trigger the measuring
  cmdst[2] = id;
  cmdst[3] = 0x00;
  cmdst[4] = 0x01;
  transmitCommands();
  //  SerialPort.println("Trigger!");
}
void urmReader(int id){  // The function is used to read the distance
  cmdst[2] = id;
  cmdst[3]=0x00;
  cmdst[4]=0x02;
  transmitCommands();
  //  SerialPort.println("Ask for distance!");
}

void transmitCommands(){  // Send protocol via RS485 interface
  cmdst[5]=cmdst[0]+cmdst[1]+cmdst[2]+cmdst[3]+cmdst[4];
  delay(1);
  for(int j = 0; j < 6; j++){
    printByte(cmdst[j]);
//    delayMicroseconds(10);
  }
  delay(3);
}


/********************* Receive the data and get the distance value from the RS485 interface ***************/

void decodeURM4(){
  
  if(SerialPort.available()){
    
    unsigned long timerPoint = millis();
    
    int RetryCounter = 0;
    byte cmdrd[10];
    for(int i = 0 ;i < 10; i++)  cmdrd[i] = 0;
    int i=0;
    
//    SerialPort.println("OK");

    boolean flag = true;
    boolean valid = false;
    byte headerNo = 0;

    while(RetryCounter < CommMAXRetry && flag)
    {
      
      if(SerialPort.available()){
        cmdrd[i]= SerialPort.read();
        
//        printByte(cmdrd[i]);
        
        if(i > 7){
          flag=false;
//          printByte(0xEE);  
//          printByte(0xFF);
          SerialPort.flush();
          break;
        }
        if(cmdrd[i] == 0xAA){
          headerNo = i;
          valid = true;
        }
        if(valid && i == headerNo + 6){
//          printByte(0xDD);
//          printByte(0xFF);
          flag = false;
          break;
        }
        i ++;
        RetryCounter = 0;
      }
      else{
        RetryCounter++;
        delayMicroseconds(15);
      }
    }
    
//    printByte(millis() - timerPoint);

    if(valid)  analyzeUrmData(cmdrd);
    else printByte(0xEC);  //Get an invalid error command
    
  }
  
}

void analyzeUrmData(byte cmd[]){
  
  byte sumCheck = 0;
  for(int h = 0;h < 7; h ++)  sumCheck += cmd[h];
  
  if(sumCheck == cmd[7] && cmd[3] == 2 && cmd[4] == 2){
    
    byte id = cmd[2] - startAddr;
    urmData[id] = cmd[5] * 256 + cmd[6];
    
//    SerialPort.print(id);
//    SerialPort.print(":");
//    SerialPort.println(urmData[id]);
    
  }
  else if(cmd[3] == 2 && cmd[4] == 2){
    SerialPort.print("Sum error");
  }
  
}


