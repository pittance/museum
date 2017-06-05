
//from http://playground.arduino.cc/Main/RotaryEncoders

//NOTES:
//  Board                               Digital Pins Usable For Interrupts
//  Uno, Nano, Mini, other 328-based    2, 3
//  Mega, Mega2560, MegaADK             2, 3, 18, 19, 20, 21

#define encoder0PinA  20
#define encoder0PinB  21

volatile unsigned int encoder0Pos = 0;

void setup() { 


  pinMode(encoder0PinA, INPUT); 
  pinMode(encoder0PinB, INPUT); 

  attachInterrupt(digitalPinToInterrupt(encoder0PinA),doEncoder, CHANGE);  // encoder pin on interrupt
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk

} 

void loop(){
// do some stuff here - the joy of interrupts is that they take care of themselves
}

void doEncoder() {
  /* If pinA and pinB are both high or both low, it is spinning
   * forward. If they're different, it's going backward.
   *
   * For more information on speeding up this process, see
   * [Reference/PortManipulation], specifically the PIND register.
   */
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
  
  //comment this out before final runs
  Serial.println (encoder0Pos, DEC);  //careful, this might fail sometimes, don't rely on it
}


