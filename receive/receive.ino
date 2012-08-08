const int motorpin1 = 4;
const int pwmpin1=3;

void setup(){
 pinMode(motorpin1, OUTPUT);
pinMode(pwmpin1, OUTPUT);
Serial.begin(9600);
digitalWrite(pwmpin1, HIGH);
digitalWrite(motorpin1, HIGH);

}

void loop(){
 while(Serial.available()>0){
   char incomingByte = Serial.read();
   Serial.println(incomingByte);
   if(incomingByte==1){
     Serial.println("one way");
     digitalWrite(pwmpin1, LOW);
        delay(250);
digitalWrite(motorpin1, LOW);
digitalWrite(pwmpin1, HIGH);
   }
   else if(incomingByte==2){
     Serial.println("other way");
digitalWrite(pwmpin1, LOW);
delay(250);
digitalWrite(motorpin1, HIGH);
digitalWrite(pwmpin1, HIGH);
   }
   else{
digitalWrite(motorpin1, LOW);
digitalWrite(pwmpin1, LOW);
Serial.println("off");
   }
 }
}
