#include <Wire.h>
#include <DueTimer.h> // Arduino Due timer


  //byte ibyte[7] = {50,150,1,2,1000000,2000000,2500000};
  byte ibyte[40];
  int i = 0;
  int j = 0;
  int in_pin_black = 2;
  int in_pin_red = 3;
  int out_pin_led = 6;
  int in_pin_but = 5;
  double time1,time2;
  bool phase_2 = false;
  bool phase_3 = false;
  bool finished_sequence = true;
  uint16_t mask = B11111111; 
  
  
void setup()
{
  Serial.begin(57600);
  delay(2500);
  Wire.begin();
  pinMode(in_pin_black,INPUT);
  pinMode(in_pin_red,INPUT);
  pinMode(out_pin_led,OUTPUT);
  pinMode(in_pin_but,INPUT_PULLUP);

}

void loop() {
  
     if(finished_sequence){
       if(digitalRead(in_pin_black)){
       time2 = millis();
       delay(100);
       Serial.write('b');
       }
       if(digitalRead(in_pin_red)){
       time2 = millis();
       int n = 4852;
       Serial.println(n);
       Serial.write(n);
       delay(100);
       Serial.write('r');
        }
     digitalWrite(out_pin_led,HIGH);
     if(digitalRead(in_pin_but)){
       Serial.println("Button test pressed");
       }

     
     }
       

}
