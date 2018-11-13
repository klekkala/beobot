     
/*
 RC PulseIn Serial Read out
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */


void rcsetup() {

  pinMode(0, INPUT); // Set our input pins as such
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);

}

int * rcloop(bool test) {

  char packet[29];
  int ch1 = pulseIn(0, HIGH, 25000); // Read the pulse width of 
  int ch2 = pulseIn(1, HIGH, 25000); // each channel
  int ch3 = pulseIn(2, HIGH, 25000);
  int ch4 = pulseIn(3, HIGH, 25000);
  int ch5 = pulseIn(4, HIGH, 25000);
  int ch6 = pulseIn(5, HIGH, 25000);

if(bool) {
  
  Serial.print("Channel 0:"); // Print the value of 
  Serial.println(ch1);        // each channel

  Serial.print("Channel 1:");
  Serial.println(ch2);

  Serial.print("Channel 2:");
  Serial.println(ch3);

  Serial.print("Channel 3:");
  Serial.println(ch4);

  Serial.print("Channel 4:");
  Serial.println(ch5);

  Serial.print("Channel 5:");
  Serial.println(ch6);

  delay(100); // I put this here just to make the terminal 
              // window happier
 }

  strcpy(packet, itoa(ch1));
  strcat(packet, ",");
  strcat(packet, itoa(ch2));
  strcat(packet, ",");
  strcat(packet, itoa(ch3));
  strcat(packet, ",");
  strcat(packet, itoa(ch4));
  strcat(packet, ",");
  strcat(packet, itoa(ch5));
  strcat(packet, ",");
  strcat(packet, itoa(ch6));

  return packet;
}
