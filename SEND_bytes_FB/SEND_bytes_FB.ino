/*
PROTEI_010
RC-->Xbee-->xbee-->arduino-->motor
 written by gabriella levine
 2012
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int powerPin = 13;
const int signalPin = 12;

const int JSTK_RIGHT = A0;  // Analog input pin that the potentiometer is attached to
const int JSTK_LEFT= A5; // Analog output pin that the LED is attached to

int sensorValueRIGHT = 0;        // value read from the pot
int sensorValueLEFT = 0;        // value read from the pot

int currentMillis = 0;
int previousMillis = 0;

int signalState = LOW;

long interval = 1000;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(powerPin, OUTPUT);
  pinMode(JSTK_RIGHT, INPUT);
  pinMode(JSTK_LEFT, INPUT);
}

void loop() {
 
  if(Serial.available()>0){
    if(Serial.read()=='1'){
  
     signalState = HIGH;
     unsigned long currentMillis = millis();
     if(currentMillis - previousMillis>interval){
       previousMillis=currentMillis;
       if(signalState ==HIGH)
       signalState=LOW;
       else
       signalState=LOW;
     }
   
      digitalWrite(signalPin, signalState);
    }
  }
      else{digitalWrite(signalPin, LOW);}

      
 

  digitalWrite(powerPin, HIGH);
  // read the analog in value:
  sensorValueRIGHT = map(analogRead(JSTK_RIGHT),0,1023,0,255);            
  Serial.print('R');
  delay(10);
  // Serial.write(outputValue9);  
  Serial.write(sensorValueRIGHT);  
  //Serial.write(250);
  delay(10);
  //delay(20);
  sensorValueLEFT = map(analogRead(JSTK_LEFT),0,1023,0,255);   
  Serial.print('L');
  delay(10);
  Serial.write(sensorValueLEFT); 
  delay(10);
  // Serial.flush();  
}



