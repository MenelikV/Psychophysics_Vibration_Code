#include <Wire.h>
#include <DueTimer.h> // Arduino Due timer


int ibyte[50];
int i = 0;
int j = 0;
int k = 0;

int in_pin_black = 2;
int in_pin_red = 3;
int in_pin_but = 5;
int out_pin_led = 6;

int duration;
double time1, time2;
bool phase_2 = false;

bool finished_sequence = false;
int indices[6];
String duration_s, test;

void setup()
{
  Serial.begin(57600);
  delay(2500);
  Wire.begin();
  pinMode(in_pin_black, INPUT);
  pinMode(in_pin_red, INPUT);
  pinMode(in_pin_but, INPUT_PULLUP);
  pinMode(out_pin_led, OUTPUT);

}


void loop ()
{
  if (Serial.available() > 0)
  {
    int y = Serial.read();
    if (y != 0 | y != 240)
    {
      ibyte[i] = y;
      Wire.beginTransmission(1);
      Wire.write(ibyte[i]);
      Wire.endTransmission();
      delay(100);
      if (i > 2 && ibyte[i] == 116 & ibyte[i - 1] == 92 )
      {
        phase_2 = true;
        Serial.write('s'); // Sending confirmation to Matlab, ascii code of s = 115
      }
      i++;
      Serial.write('s');
       if(ibyte[j] == 'n')
        {
          indices[k] = j-2;
          k++;
        }
    }
  }

  if (phase_2)
  {
    i++;
    delay(100);
    for(i=0;i<50;i++)
    {
      test += ibyte[i];
    }
    duration_s = test.substring(indices[4]+3,indices[5]+1);
    duration = duration_s.toInt();
    delay(2 * duration);
    finished_sequence = true;
    time1 = millis();
    phase_2 = false;
  }

  
  if (finished_sequence)
  {
    if (digitalRead(in_pin_black))
    {
      time2 = millis();
      Serial.println(time2 - time1);
      delay(100);
      Serial.write('b');
    }
    if (digitalRead(in_pin_red))
    {
      time2 = millis();
      Serial.println(time2 - time1);
      delay(100);
      Serial.write('r');
    }
  }
}
