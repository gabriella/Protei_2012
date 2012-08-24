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

int signalState = 0;

long interval = 200;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(powerPin, OUTPUT);
  pinMode(JSTK_RIGHT, INPUT);
  pinMode(JSTK_LEFT, INPUT);
  pinMode(signalPin, OUTPUT);
}

void loop() {

  if(Serial.available()>0){
    if(Serial.read()=='1'){
      digitalWrite(signalPin, HIGH);
      signalState = 1;
    }
    signalState = 0;
  }
  else if(signalState ==0){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis>interval){
      previousMillis=currentMillis;
      digitalWrite(signalPin, LOW);
    }
  }




  digitalWrite(powerPin, HIGH);
  // read the analog in value and map it, 866 to 108
  sensorValueRIGHT = map(analogRead(JSTK_RIGHT),200,860,0,255);     
   sensorValueRIGHT= constrain(sensorValueRIGHT,0,255);

Serial.print('a');
delay(10);

  Serial.print('R');
  delay(10);
  // Serial.write(outputValue9);  
  Serial.write(sensorValueRIGHT);  
  //Serial.write(250);
  delay(10);
  //delay(20);
  sensorValueLEFT = map(analogRead(JSTK_LEFT),200,860,0,255);
   sensorValueLEFT = constrain(sensorValueLEFT, 0,255);

  Serial.print('L');
  delay(10);
  Serial.write(sensorValueLEFT); 
  delay(10);
  Serial.flush();  
}





