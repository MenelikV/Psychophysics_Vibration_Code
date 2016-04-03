//
// BubbleBoy -> Matlab
// ——————-
//
// Read LDR data, print them to Serial (where Matlab will receive them)
//
  
void setup() {
 
  Serial.begin(57600);
  analogReadResolution(12);
 
}
 
void loop() {
  
  delay(2000);
  
  while(true){
  uint16_t sensorValue = analogRead(A0);
 //Serial.println(sensorValue, DEC);
  Serial.println(sensorValue);
 
 
// //uint16_t number = 5703;               // 0001 0110 0100 0111
// uint16_t mask   = B11111111;          // 0000 0000 1111 1111
// uint8_t first_half   = sensorValue >> 8;   // >>>> >>>> 0001 0110
// uint8_t second_half = sensorValue & mask; // ____ ____ 0100 0111
// Serial.write(first_half);
// Serial.write(second_half);
 delay(1);
  }
 
}
