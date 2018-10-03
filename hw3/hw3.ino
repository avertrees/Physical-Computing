/*
  Analog Input
 Demonstrates analog input by reading 4 potentiameter values on analog pins 0, 1, 2, and 3 and changing the red, green, blue, and 
 brightness values of an RGB LED according to the potentiometer readings, respectively. 
 The RGB LED is connected to digital pins 2, 3, 4, and 5. The amount of each value of of the RGB LED will be change depending on
 the value obtained by analogRead().

 The circuit:
 * 4 Potentiometers attached to analog input 0, 1, 2, and 3
 * center pin of the potentiometer to the analog pins
 * one RGB LED connected to pins 9-11 
 */

int sensorPinR = A0;    // select the input pin for the first potentiometer
int sensorPinG = A1;    // select the input pin for the second potentiometer
int sensorPinB = A2;    // select the input pin for the third  potentiometer
int sensorPinI = A3;    // select the input pin for the fourth potentiometer

//LED Pins
int ledDigitalOne[] = {9, 10, 11}; //Array of RGB LED pins
 
//potentiometers
int sensorValueR = 0;  // variable to store the value coming from the sensor
int sensorValueG = 0;  // variable to store the value coming from the sensor
int sensorValueB = 0;  // variable to store the value coming from the sensor
int sensorValueI = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  for(int i = 0; i < 3; i++){
    //  set the 3 pins as outputs
    pinMode(ledDigitalOne[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorPinR=sensorPinR/4;
  sensorPinG=sensorPinG/4;
  sensorPinB=sensorPinB/4;
  sensorValueR = analogRead(sensorPinR);
  sensorValueG = analogRead(sensorPinG);
  sensorValueB = analogRead(sensorPinB);
//  sensorValueI = analogRead(sensorPinI);
  
//  setColor(ledDigitalOne, sensorValueR, sensorValueG, sensorValueB);
  //Serial.println("red: ", sensorValueR, " green: ", sensorValueG, " blue: ", sensorValueB);
  Serial.print("Red: ");
  Serial.println(sensorValueR);
  Serial.print("Green: ");
  Serial.println(sensorValueG);
  Serial.print("Blue: ");
  Serial.println(sensorValueB);
  Serial.print("I: ");
  Serial.println(sensorValueI);
  Serial.print(" ");
  delay(100);
  
  // turn the ledPin on
  analogWrite(ledDigitalOne[0], sensorValueR);
  analogWrite(ledDigitalOne[1], sensorValueG);
  analogWrite(ledDigitalOne[2], sensorValueB);
  //delay(sensorValueI);
}
