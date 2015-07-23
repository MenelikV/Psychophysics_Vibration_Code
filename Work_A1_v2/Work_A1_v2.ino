
#include <Wire.h>

int length = 96;
byte data[96];
int j = 0;
bool received_data =  false;
int i = 0;
byte number_bytes[16];

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(57600);  // start serial for output
}

void loop()
{
  Wire.requestFrom(1, length);    // request 6 bytes from slave device #2

  while(Wire.available() > 0)    // slave may send less than requested
  {
    
    data[j] = Wire.read(); // receive a byte as character
    j++;
    if(j == 96)
    {
      received_data = true;
    }  
  }
  
  delay(500);
  if(received_data)
  {
    Serial.println("So weit, so gut :D");
    for(i=0;i=15;i++)
    {
      number_bytes[i] = data[i];
    }
    int a = (int) number_bytes;
    Serial.println(a);
  }
}

