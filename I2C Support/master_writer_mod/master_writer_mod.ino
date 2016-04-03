// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

// Arduino Address 1

#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);           // start serial for output
  Wire1.begin(2); // join i2c bus with address #2
  
}

byte x = 0;

void loop()
{
  Wire.beginTransmission(2); // transmit to device #2
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte  
  Serial.println(x);         // print the integer
  Wire.endTransmission();    // stop transmitting
  
  Wire1.onReceive(receiveEvent); // register event

  x++;
  delay(500);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire1.available()) // loop through all but the last
  {
    char c = Wire1.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int a = Wire1.read();    // receive byte as an integer
  Serial.println(a);         // print the integer
}
