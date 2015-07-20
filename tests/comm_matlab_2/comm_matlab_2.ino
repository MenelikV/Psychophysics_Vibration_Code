int rbyte[10];
void setup()
{
  Serial.begin(57600);
  delay(2500);
}
int i = 0;
byte a;
int f1 = 0;
bool Start = false;

void loop()
{
  if(Start)
  { 
    if(Serial.available()>0)
    {
    for(i=0;i=10;i++)
    {
     rbyte[i]=Serial.read();
     Serial.write(rbyte[i]);
     delay(1);
     }
    }
   }
 }
  
void serialEvent() {
  if (Serial.available()>0) {
 
    // get the new byte:
    a = Serial.read();
   if(a == 115)// bytes Code for s
   {
   Start = true;}
    }
  }

  


