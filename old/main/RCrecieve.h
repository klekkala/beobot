
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

float * rcloop(bool test) {

  int channels = 6;
  char packet[49];
  float ch[channels];
  int i;
  for(i=0; i< channels; i++){
    ch[i] = pulseIn(i, HIGH, 25000); // Read the pulse width of 
  }

if(test) {
  
  Serial.print("Channel 0:"); // Print the value of 
  Serial.println(ch[0]);        // each channel

  Serial.print("Channel 1:");
  Serial.println(ch[1]);

  Serial.print("Channel 2:");
  Serial.println(ch[2]);

  Serial.print("Channel 3:");
  Serial.println(ch[3]);

  Serial.print("Channel 4:");
  Serial.println(ch[4]);

  Serial.print("Channel 5:");
  Serial.println(ch[5]);

  delay(100); // I put this here just to make the terminal 
              // window happier
 }
  
  return ch;
}
