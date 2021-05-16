//Sender Code
#include "RCrecieve.h"

char str[8][4];

void setup() {
  Serial1.begin(9600);
  rcsetup();
}

void loop() {
  char *value = rcloop(False);
  Serial.write(value);
}
