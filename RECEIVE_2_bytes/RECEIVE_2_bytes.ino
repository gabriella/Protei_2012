/*
Serial commo from xbee with xbee's pin 2 and 3 connected to rx1, tx1
 */
int incomingData;
int incomingDataInt;
const int OUTPUT_1 = 3; // Analog output pin that the Motor1 pwm pin is attached to
const int DIR_PIN_1=4; //digital output for logic direction pin motor 1
const int OUTPUT_2= 5; // Analog output pin that the MOTOR2 pwm pin is attached to
const int DIR_PIN_2 = 6;//digitaloutput for logic direction pin motor2

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
      if(incomingDataInt<=100){
       digitalWrite(DIR_PIN_1, LOW); 
      }
        else if(incomingDataInt>=200){
       digitalWrite(DIR_PIN_1, HIGH); 
      }
     // Serial.println(incomingDataInt);
      sensorState = 0;
    }

    else if (sensorState == 2) {
      //analogWrite(OUTPUT_1, incomingDataInt);
      sensorState =0 ;
    }
  }
  delay(20);
  Serial.flush();
}


