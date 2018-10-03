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
//ledPins
int ledRed = 9;         //red pin
int ledGreen = 10;      //green pin
int ledBlue = 11;       // blue pin

//potentiometers
int sensorValueR = 0;  // variable to store the value coming from the sensor
int sensorValueG = 0;  // variable to store the value coming from the sensor
int sensorValueB = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValueR = analogRead(sensorPinR)/4;  //range of pot. is 0-1023, 
  sensorValueG = analogRead(sensorPinG)/4;  //in order to get a range from 0-255
  sensorValueB = analogRead(sensorPinB)/4;  //I divided the raw sensor data by 4
 
  // turn the ledPin on
  analogWrite(ledRed, sensorValueR);        //set color value to sensor value
  analogWrite(ledGreen, sensorValueG);      //set color value to sensor value
  analogWrite(ledBlue, sensorValueB);       //set color value to sensor value
  delay(1000);

  //print values
  Serial.print("Red: ");
  Serial.println(sensorValueR);
  Serial.print("Green: ");
  Serial.println(sensorValueG);
  Serial.print("Blue: ");
  Serial.println(sensorValueB);
  Serial.print(" ");

}



