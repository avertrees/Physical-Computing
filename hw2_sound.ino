// CIRC06 - Music with Piezo
  
int speakerPin = 10;
int length = 32; // the number of notes
char notes[] = "gg   gg   gg      gg      gg       ff   ff   ff      ff      ff       "; // a space represents a rest
int beat = 1;
int tempo = 128;
 
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
  pinMode(speakerPin, OUTPUT);
  for(int i = 0; i < 8; i++){         //this is a loop and will repeat 8 times
     pinMode(ledPins[i],OUTPUT);      //we use this to set each LED pin to output
  }
    
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 87, 97, 1136, 1014, 956 };  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      tone(speakerPin, tones[i], duration);
    }
  }
}

 
/*
 * loop() - this function will start after setup finishes and then repeat.
 * delayTime (milliseconds)
 * This loop turns o
 */
int count = 0; 
int beatcount = 0;
void loop()                     // run over and over again
{
  int delayTime = 128;  
    /*Turn each LED on, one at a time. Variable 'i' is incrimented by 1 in each iteration,
     * so this will repeat 8 times (bc zero indexing) before i <= 7 
     *When the loop is over, 'i' will equal 8, which is the index of the 8th pin in the ledPins[] array.
     *after the LED is turned on, there is a delay
    */
  for(int i = 0; i <= 7; i++){
    digitalWrite(ledPins[i], HIGH);  //Turns on the LED which is connected to 
                                      //the pin corresponding to the int stored in ledPins[]
                                      //at index i.
    if(count < 7){
      if (notes[i] != ' ') {
        playNote(notes[i], beat * tempo);
      }                                 
    } else {
      int j = (count * 8) % i;
      if (notes[length%j] != ' ') {
        playNote(notes[length%j], beat * tempo);
      }        
    }

    delay(delayTime);
    
    count++;             
  }

 
  
  /*
   * Turn each LED off, one at a time
   * Variable 'i' is decremented by 1 in each iteration,
   * so this will repeat 8 times (bc zero indexing) before i <= 0 
   * When the loop is over, 'i' will equal 0, which is the index
   * of the 1st pin in the ledPins[] array.
   after the LED is turned off, there is a delay */
  for(int i = 7; i >= 0; i--){  //same as above but this time we are decrementing the value of i by 1
    digitalWrite(ledPins[i], LOW);  //Turns off the LED which is connected to
    
    if(count < 7){
      if (notes[i] != ' ') {
        playNote(notes[i], beat * tempo);
      }                                 
    } else {
      int k = (count * 8)%i;
      if (notes[length%k] != ' ') {
        playNote(notes[length%k], beat * tempo);
      }        
    }
   
    delay(delayTime);                //the pin corresponding to the int stored in ledPins[] at index i. 
    count++;                              
  }

}

