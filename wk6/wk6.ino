//void changeLED(int led, int state);
int data = 2; 
int clock = 3;
int latch = 4;

//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

int num = 8; //global number of LEDs for loops to access
int leds[8] = {0, 1, 2, 3, 4, 5, 6, 7}; //array of LEDs for ref                       

  
void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);  
  pinMode(latch, OUTPUT);  
}


void loop()                     
{ //randomly generate 8 numbers between 0 and 1 that will be stored in the leds array
  for(int i = 0; i < num; i++){
    leds[i] = random(0,2);
  }
  int delayTime = 100; //time that lights will be on
  
  //int numOn = random(num); //randomly generate a number between 0 and 8 every time loop() is called
  
  for(int i = 0; i<num; i++){ // go through the leds[] array and light up the randomly generated light pattern
    if(leds[i]){ //if led[i] is 1, turn it on
      changeLED(i,ON);
    } else {  //otherwise, turn it off.
      changeLED(i, OFF);
    delay(delayTime);
  }

}
}

//Functions from tutorial

//These are used in the bitwise math that we use to change individual LEDs
//For more details http://en.wikipedia.org/wiki/Bitwise_operation
int bits[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};

/*
 * changeLED(int led, int state) - changes an individual LED 
 * LEDs are 0 to 7 and state is either 0 - OFF or 1 - ON
 */
 void changeLED(int led, int state){
   ledState = ledState & masks[led];  //clears ledState of the bit we are addressing
   if(state == ON){ledState = ledState | bits[led];} //if the bit is on we will add it to ledState
   updateLEDs(ledState);              //send the new LED state to the shift register
 }

/*
 * updateLEDs() - sends the LED states set in ledStates to the 74HC595
 * sequence
 */
void updateLEDs(int value){
  digitalWrite(latch, LOW);     //Pulls the chips latch low
  shiftOut(data, clock, MSBFIRST, value); //Shifts out the 8 bits to the shift register
  digitalWrite(latch, HIGH);   //Pulls the latch high displaying the data
}
