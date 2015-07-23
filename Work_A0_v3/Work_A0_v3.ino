#include <Wire.h>
#include <DueTimer.h> // Arduino Due timer


int in_pin_black = 2;
int in_pin_red = 3;
int in_pin_but = 5;
int out_pin_led = 6;

int duration;

double time1, time2;
bool finished_sequence = false;


char buffer[96];
int length = 96;

void setup() 
{
  Wire.begin(1);
  Wire.onRequest(requestEvent); // register event
  Serial.begin(57600);
  pinMode(in_pin_black, INPUT);
  pinMode(in_pin_red, INPUT);
  pinMode(in_pin_but, INPUT_PULLUP);
  pinMode(out_pin_led, OUTPUT);
  delay(2500);
}

void loop()
{
  if(Serial.available()>0)
  {
    Serial.readBytes(buffer,length);
    delay(50);
  }
  if(strlen(buffer) == length)
  {
    Serial.write('s');
  }

}

void requestEvent()
{
  Wire.write(buffer);
}


