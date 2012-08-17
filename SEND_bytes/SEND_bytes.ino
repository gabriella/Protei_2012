/*
RC-->Xbee-->xbee-->maple-->motor
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int powerPin = 13;


const int JSTK_RIGHT = A0;  // Analog input pin that the potentiometer is attached to
const int JSTK_LEFT= A5; // Analog output pin that the LED is attached to

int sensorValueRIGHT = 0;        // value read from the pot
int sensorValueLEFT = 0;        // value read from the pot

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(powerPin, OUTPUT);
  pinMode(JSTK_RIGHT, INPUT);
  pinMode(JSTK_LEFT, INPUT);
}

void loop() {
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

