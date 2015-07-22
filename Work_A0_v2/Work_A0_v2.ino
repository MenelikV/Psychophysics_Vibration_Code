#include <Wire.h>
#include <DueTimer.h> // Arduino Due timer


int ibyte[50];
int i = 0;
int j = 0;
int k = 0;
int l = 0;
int length = 8;
bytes buffer[96]

int in_pin_black = 2;
int in_pin_red = 3;
int in_pin_but = 5;
int out_pin_led = 6;
int duration;
double time1, time2;

bool phase_2 = false;
bool phase_3 = false;
bool finished_sequence = false;
uint16_t mask = B11111111; // Bitmask to improve the bit resolution

void setup()
{
  Wire.begin();
  Serial.begin(57600);
}

void loop () 
{
  if (Serial.available() > 0){
    Serial.readBytes(buffer, length);
    
