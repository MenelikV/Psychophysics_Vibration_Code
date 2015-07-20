#include <Wire.h>
#include <DueTimer.h> // Arduino Due timer


  byte ibyte[18];
  int i = 0;
  int j = 0;
  int k = 0;
  int in_pin_black = 2;
  int in_pin_red = 3;
  int in_pin_but = 5;
  int out_pin_led = 6;
  int duration1, duration2;
  double time1,time2;
  bool phase_2 = false;
  bool phase_3 = false;
  bool finished_sequence = false;
  uint16_t mask = B11111111; // Bitmask to improve the bit resolution
  
void setup()
{
  Serial.begin(57600);
  delay(2500);
  Wire.begin();
  pinMode(in_pin_black,INPUT);
  pinMode(in_pin_red,INPUT);
  pinMode(in_pin_but, INPUT_PULLUP);
  pinMode(out_pin_led,OUTPUT);

}


void loop (){
  
  
      if(Serial.available() > 0){
       char y = Serial.read();
       k = i;
       if(y != 0){
       ibyte[i] = y;
       Wire.beginTransmission(1);
       Wire.write(ibyte[i]);
       Wire.endTransmission();
       delay(100);
       i++;
       Serial.write('s');
       }}
     
       else{
         if(k == i-1){
          phase_2 = true;
          Wire.beginTransmission(1);
          Wire.write(ibyte[k]);
          Wire.endTransmission();
          delay(100);
          Serial.write('s'); // Sending confirmation to Matlab, ascii code of s = 115
        }
       }

     
     
  
     if(phase_2){  
      i++;
      Wire.beginTransmission(1);
      Wire.write(ibyte[k]);
      Wire.endTransmission();
      delay(100);
      delay(duration1+duration2);
      finished_sequence = true;
      time1 = millis();
      phase_2 = false;
}
      
     
     
     
     if(finished_sequence){
       if(digitalRead(in_pin_black)){
       time2 = millis();
       Serial.println(time2-time1);
       delay(100);
       Serial.write('b');
       }
       if(digitalRead(in_pin_red)){
       time2 = millis();
       Serial.println(time2-time1);
       delay(100);
       Serial.write('r');
        }

     
     }
  }
