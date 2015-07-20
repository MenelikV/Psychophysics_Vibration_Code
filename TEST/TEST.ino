int i;
bool phase_2;

void setup() {
  Serial.begin(57600);
  i = 0;
  phase_2 = false;
}

void loop() {
      if(i<8){
       Serial.println(i);
       //ibyte[i]=Serial.read();
       i++;
       }
       else{
         if(i == 8){
       phase_2 = true;}
     }
     if(phase_2){
     Serial.println('s');
   phase_2 = false;
  i++;}

}
