//setup software serial for communication with simple motor controller
#include <SoftwareSerial.h>
// software serial #1: RX = digital pin 11, TX = digital pin 10
// don't use 8&9 on mega
SoftwareSerial portOne(11, 10);



void setup() {
  // put your setup code here, to run once:
  
  // Start software serial port
  portOne.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}
