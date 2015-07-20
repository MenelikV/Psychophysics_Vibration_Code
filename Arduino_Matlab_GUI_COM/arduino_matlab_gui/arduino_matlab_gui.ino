int x;

int y;

int z;

void setup() {

pinMode(2,OUTPUT);

pinMode(6,OUTPUT);

pinMode(10,OUTPUT);

Serial.begin(9600);
}

void loop() {

if (Serial.available()>0) // check if Serial data is available to read
{

    x = Serial.parseInt();

    y = Serial.parseInt();

    z = Serial.parseInt();

   if (Serial.read() == '\n') // check if ENTER has been pressed (newline)
   { 
      Serial.println('success');
    }
 }
}
