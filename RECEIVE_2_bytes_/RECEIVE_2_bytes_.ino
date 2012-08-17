/*
Serial commo from xbee with xbee's pin 2 and 3 connected to rx1, tx1
 */
int incomingData;
int incomingDataInt;
const int OUTPUT_1 = 11; // Analog output pin that the Motor1 pwm pin is attached to
const int DIR_PIN_1=13; //digital output for logic direction pin motor 1
const int OUTPUT_2= 10; // Analog output pin that the MOTOR2 pwm pin is attached to
const int DIR_PIN_2 = 12;//digitaloutput for logic direction pin motor2

int sensorState = 0;  //set sensor state to be either 0 (for Left, incoming data 'L') or 1(for Right, incoming data  'R');
int previousState;

int data;
void setup() {
  // initialize serial communications at 9600 bps:
  pinMode(OUTPUT_1,OUTPUT);
  pinMode(OUTPUT_2,OUTPUT);
  pinMode(DIR_PIN_1, OUTPUT);
  pinMode(DIR_PIN_2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  while (Serial.available() > 0) {
    byte incomingData = Serial.read();
    incomingDataInt = (int)incomingData;

    if(incomingData=='L'){
      sensorState = 1; // go to state 1, waiting for R data
    } 
    else  if (incomingData == 'R') {
      sensorState = 2;
    } 
    else if (sensorState == 1) {
      analogWrite(OUTPUT_1, incomingDataInt);
      if(incomingDataInt<=120){
        digitalWrite(DIR_PIN_1, LOW); 
        analogWrite(OUTPUT_1,map(incomingDataInt, 120,0,0,255));
      }
      else if(incomingDataInt>=150){
        digitalWrite(DIR_PIN_1, HIGH); 
        analogWrite(OUTPUT_1,map(incomingDataInt, 150,255,0,255));
      }
      else{
        digitalWrite(OUTPUT_1, LOW);
      }
      // Serial.println(incomingDataInt);
      sensorState = 0;
    }

    else if (sensorState == 2) {
         analogWrite(OUTPUT_2, incomingDataInt);
      if(incomingDataInt<=120){
        digitalWrite(DIR_PIN_2, LOW); 
        analogWrite(OUTPUT_2,map(incomingDataInt, 120,0,0,255));
      }
      else if(incomingDataInt>=150){
        digitalWrite(DIR_PIN_2, HIGH); 
        analogWrite(OUTPUT_2,map(incomingDataInt, 150,255,0,255));
      }
      else{
        digitalWrite(OUTPUT_2, LOW);
      }
      sensorState =0 ;
    }
  }
  delay(20);
  Serial.flush();
}



