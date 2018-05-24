/*
# The Sample code for driving single URM04 measuring distance function

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

#include "Urm4parser.h"

void setup(){
  urmInit();      // Init the URM04 sensor
}

void loop(){
  static unsigned long timePoint = 0;

  runUrm4();      // Drive URM04 Sensor and transmit the protocol to the sensor via RS485 interface
                  // (IO Expansion shield V5 for arduino)
  decodeURM4();   // Read and get the distance value from the sensor
  if(millis() - timePoint > 100){
    PrintData();  // print the data
    timePoint = millis();
  } 
//  PrintData();
//  delay(100);

}

void PrintData(){
  
  Serial.print("Distance value:  ");
  for(int i = 0; i < urmAccount; i++){
    Serial.print(urmData[i]);
    Serial.print(" ");
  }
/*
  for(int i = 0; i < urmAccount;i ++){
    Serial.print(urmID[i],HEX);
    Serial.print(" ");
  }
*/
  Serial.println();
}
