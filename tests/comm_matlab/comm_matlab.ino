//Probelms with numbers higher than 255, there is a roll over.

char ibyte;
int i = 0;

int f1 = 4;  // 0 - 750
int f2 = 5;
int a1 = 256; // 0 - 4095
int table[3];

void setup()
{
  Serial.begin(57600);
  delay(2500);
  table[0] = f1;
  table[1] = f2;
  table[2] = a1;
}


void loop()
{
  if(true)//Serial:available valid if something has to be recived
  {
    //ibyte=Serial.read();
    //Serial.write(ibyte);
    Serial.write(table[i],'int16');
    i++;
    delay(1);
  }
}
  
