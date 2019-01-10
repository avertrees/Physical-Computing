// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      144

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  //pixels.begin(); // This initializes the NeoPixel library.

  strip.begin(); // This initializes the NeoPixel library.
  strip.show();
}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    if(i < 77){
      strip.setPixelColor(i, strip.Color(0,0,255)); // Moderately bright green color.
//      strip.show(); // This sends the updated pixel color to the hardware.

    } else {
      strip.setPixelColor(i, strip.Color(255,0,0)); // Moderately bright green color.
      //strip.show(); // This sends the updated pixel color to the hardware.

    }
        strip.show(); // This sends the updated pixel color to the hardware.

  }
  
  //rainbowCycle(20);
  
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  //for(int i=0;i<NUMPIXELS;i+=2){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    //pixels.setPixelColor(i, pixels.Color(150,0,150)); // Moderately bright green color.
    
    // pixels.show(); // This sends the updated pixel color to the hardware.

    //delay(delayval); // Delay for a period of time (in milliseconds).

}

  
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256*3; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//hsl(180, 100%, 50%) to hsl(0, 100%, 50%)
  // Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
