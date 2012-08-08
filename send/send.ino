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
