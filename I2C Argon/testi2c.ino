// This #include statement was automatically added by the Particle IDE.
#include <OneWire.h>


#define MyAddress 0x10

const int ledPin = 5; 
 
void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(MyAddress);
  
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  
  // Setup pin 13 as output and turn LED off
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}
 
// Function that executes whenever data is received from master
void receiveEvent(int byteCount) {
  while (Wire.available()) { // loop through all but the last
    int c = Wire.read(); // receive byte as a number
    if (c == 0)
    {
        digitalWrite(ledPin, LOW);
    }
    else if (c == 1)
    {
        digitalWrite(ledPin, HIGH);
    }
  }
}
void loop()
{
  delay(2000);
}