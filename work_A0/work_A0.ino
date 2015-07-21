#include <Wire.h>
#include <DueTimer.h> // Arduino Due timer


  int ibyte[50];
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int in_pin_black = 2;
  int in_pin_red = 3;
  int in_pin_but = 5;
  int out_pin_led = 6;
  int duration;
  double time1,time2;
  bool phase_2 = false;
  bool phase_3 = false;
  bool finished_sequence = false;
  uint16_t mask = B11111111; // Bitmask to improve the bit resolution
  char data_string[6][6];
  int indices[6];
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
       int y = Serial.read();
       if(y != 0 | y != 240){
       ibyte[i] = y;
       Wire.beginTransmission(1);
       Wire.write(ibyte[i]);
       Wire.endTransmission();
       delay(100);
       i++;
       Serial.write('s');
         if(j > 2 && ibyte[j] == 110 & ibyte[j-1] == 92){
          indices[k] = j;
          k++;
           if(k>0){
              for(l = indices[k-1]; l = indices[k]; l++){
                  data_string[k][l] = ibyte[l];}
  }}
       }}
     
       else{
         if(i > 2 && ibyte[i] == 116 & ibyte[i-1] == 92 ){
          phase_2 = true;
          Serial.write('s'); // Sending confirmation to Matlab, ascii code of s = 115
        }
       }

     
     
  
     if(phase_2){  
      i++;
      delay(100);
      duration = atoi(data_string[5]);
      delay(2*duration);
      finished_sequence = true;
      time1 = millis();
      phase_2 = false;}

      
     
     
     
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
