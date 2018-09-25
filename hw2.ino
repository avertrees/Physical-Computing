/*
 * Set up a global array of ledPins that correspond to the pins used on the arduino
 * Size of array is defined at 
 */
int ledPins[] = {2,3,4,5,6,7,8,9};

/*
 * loop() - this function will start after setup finishes and then repeat.
 */
void setup()
{
  for(int i = 0; i < 8; i++){         //this is a loop and will repeat 8 times
     pinMode(ledPins[i],OUTPUT);      //we use this to set each LED pin to output
  }
    
}

/*
 * loop() - this function will start after setup finishes and then repeat.
*/
void loop()                           // run over and over again
{
  int delayTime = 128;                //is in (milliseconds)

  /*
    Step 1: Turn on the LEDs
    This loop turns on each LED. Variable 'i' is incrimented by 1 in each iteration, so this will 
    repeat 8 times (bc zero indexing) before i <= 7. When the loop is over, 'i' will equal 8, 
    which is the index of the 8th pin in the ledPins[] array. After the LED is turned on, there is 
    a delay. 
  */
  for(int i = 0; i <= 7; i++){        
    digitalWrite(ledPins[i], HIGH);   //Turns on the LED which is connected to item i in ledPins[]
     delay(delayTime);                //delay          
  }

  
  /*
    Step 2: Turn off the LEDs
    Turn each LED off, one at a time. Variable 'i' is decremented by 1 in each iteration, so this 
    will repeat 8 times (bc zero indexing) before i <= 0 When the loop is over, 'i' will equal 0, 
    which is the index of the 1st pin in the ledPins[] array. after the LED is turned off, there 
    is a delay 
  */
  for(int i = 7; i >= 0; i--){        //same as above but decrementing the value of i by 1
    digitalWrite(ledPins[i], LOW);    //Turns off the LED which is connected to item i in ledPins[]
    delay(delayTime);                 //delay                      
  }

}

