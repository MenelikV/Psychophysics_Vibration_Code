#include <Wire.h>
 
void setup()
{
    Wire.begin();
    Serial.begin(9600);
}
 
 
void loop()
{
    delay(2000);
     
    int16_t bigNum, smallNum;

 
    byte a,b;
    Wire.requestFrom(54,2);
     
    a = Wire.read();
    b = Wire.read();
 
    smallNum = a;
    bigNum = smallNum << 8 | b;
     
    Serial.print(bigNum);
    Serial.print("\n");
}
