char ibyte;
int i = 0;
int j = 0;
int f1 = 4;  // 0 - 750
int f2 = 5;
int a1 = 700; // 0 - 4095
int r = 0;
int q = 0;
bool number = false;
uint16_t table[3];
uint16_t mask = B11111111; 

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
  if(true) //Serial:available only valid is somethig has to be received by the arduino
  {
    //ibyte=Serial.read();
    //Serial.write(ibyte);
    Serial.write(table[i] >> 8);//Fist half of the number, created with a bitshift of 8 bits
    Serial.write(table[i] & mask);// Second half, created by the 16 bit integer filtered with the mask
    i++;
    delay(1);
  }
}
  
