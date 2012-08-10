//system constants
const int JOYST_LEFT=A0;
const int JOYST_RIGHT=A5;
//sketch variables
void setup(){
 Serial.begin(9600); 
}
void
loop(){
  Serial.write(1);
  delay(500);
 Serial.write(2);
 delay(500);
}
