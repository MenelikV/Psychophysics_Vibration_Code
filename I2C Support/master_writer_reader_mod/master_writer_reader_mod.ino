// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  //Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

byte x = 0;

void loop()
{
  //Sending data
  Wire.beginTransmission(2); // transmit to device #2
  Wire.write("x is ");        // sends five bytes
  Serial.print("x is ");         // print the character
  Wire.write(x);              // sends one byte
  Serial.println(x);         // print the character
  Wire.endTransmission();    // stop transmitting
  x++;
  delay(500);
  
  //Receiving data
  Wire.requestFrom(2, 6);    // request 6 bytes from slave device #2

  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
  delay(500);
}
