/**
 * NeoPixel HSL
 * 
 * Author: E. Scott Eastman
 * Date: Feb 2017 
 * 
 * Add HSL to RGB Color space conversion. Originially designed to 
 * work with the Adafruit NeoPixel Library
 * 
 * MIT License
 * Copyright (c) 2017 E. Scott Eastman (Mazaryk)
 * 
 * Author is not associated with Adafuit or NeoPixel 
 */

#include <Adafruit_NeoPixel.h>

#define PIN 6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 432

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint16_t lowHue = 0; //263; //purple 263 //blue 231; //0 = low
uint16_t highHue = 360; //289; // purple 289 // red 359; 360 = high

uint16_t h = lowHue;  //0;

int state = 0; // 0 for incriment 1 for decrimenting hue values 

void setup() {
  Serial.begin(9600);
  strip.begin();
  //strip.show(); 
}

void loop() {
  //demo_rotate();
  //demo_random();
  
  //Serial.println("Hue ");
  //Serial.println(h);
  //Serial.println("State ");
 // Serial.println(state);

  Serial.println("Hue ");
  Serial.println(h);
  Serial.println("State ");
  Serial.println(state);
  
  if(state == 0){
    h+=5;
  } else if (state == 1) {
    h-=5;
  }
  if(h >= highHue){
    state = 1;
  } else if (h <= lowHue) {
    state = 0;
  } 
  
  demo_setHue(h);

  /*
  //delay(40);
  static int n = strip.numPixels();
  //static int n = NUMPIXELS;
  Serial.println("Number of pixels ");
  Serial.println(n);
  uint16_t hue = h; //0; // 0-359
  Serial.println("hue ");
  Serial.println(hue);
  uint8_t saturation = 100; // 0-100
  uint8_t lightness = 50; // 0-100
  
  uint32_t color;
  //int i; 

  for(int i=0; i < n; i++) {
    color = hsl(hue, saturation, lightness);
    //Serial.println("index ");
    //Serial.println(i);
    Serial.println("color ");
    Serial.println(color);
    //color = hsl(hue++, saturation, lightness);
    //Serial.println("this Pixel ");
    //Serial.println(i);
    strip.setPixelColor(i, color);
//    Serial.println("index ");
//    Serial.println(i);
//    Serial.println("color ");
//    Serial.println(color);
    //strip.setPixelColor((i+n/3)%n, color);
    //strip.setPixelColor((i+n/3*2)%n, color);
    strip.show();
    //delay(40);
  }
  */

  
  delay(40);
  
}

/**
 * Demo setHue
 * 
 * Set hue of pixels to designated color.
 * 
 */
void demo_setHue(uint16_t h) { 

  static int n = strip.numPixels();
  //static int n = NUMPIXELS;
  Serial.println("Number of pixels ");
  Serial.println(n);
  uint16_t hue = h; //0; // 0-359
  uint8_t saturation = 100; // 0-100
  uint8_t lightness = 50; // 0-100
  
  uint32_t color;
  int i; 
  
  for(i=0; i < n; i++) {
    color = hsl(hue, saturation, lightness);
    //color = hsl(hue++, saturation, lightness);
    Serial.println("this Pixel ");
    Serial.println(i);
    Serial.println("hue ");
    Serial.println(hue);
    strip.setPixelColor(i, color);
    //strip.setPixelColor((i+n/3)%n, color);
    //strip.setPixelColor((i+n/3*2)%n, color);
    strip.show();
    delay(40);
  }

  //hue %= 360;
}

/**
 * Demo Rotate
 * 
 * Iterate through the hues, one pixel at time, 
 * and divide the strip into 3 equal parts.
 */
void demo_rotate() { 

  static uint8_t n = strip.numPixels();
  
  static uint16_t hue = 0; // 0-359
  uint8_t saturation = 100; // 0-100
  uint8_t lightness = 50; // 0-100
  
  uint32_t color;
  uint8_t i; 
  
  for(i=0; i < n; i++) {
    color = hsl(hue++, saturation, lightness);
    strip.setPixelColor(i, color);
    strip.setPixelColor((i+n/3)%n, color);
    strip.setPixelColor((i+n/3*2)%n, color);
    strip.show();
    delay(40);
  }

  hue %= 360;
}



/**
 * Demo Random
 * 
 * Random Pixel, Random Color
 */
void demo_random() { 

  uint8_t pixel = random(0, strip.numPixels());
  uint16_t hue = random(0, 360);
  uint8_t saturation = 100;
  uint8_t lightness = 50;
  
  strip.setPixelColor(pixel, hsl(hue, saturation, lightness));
  strip.show();
}



/**
 * Map HSL color space to RGB
 * 
 * Totally borrowed from:
 * http://www.niwa.nu/2013/05/math-behind-colorspace-conversions-rgb-hsl/ 
 * 
 * Probably not the most efficient solution, but 
 * it get's the job done.
 */
uint32_t hsl(uint16_t ih, uint8_t is, uint8_t il) {

  float h, s, l, t1, t2, tr, tg, tb;
  uint8_t r, g, b;

  h = (ih % 360) / 360.0;
  s = constrain(is, 0, 100) / 100.0;
  l = constrain(il, 0, 100) / 100.0;

  if ( s == 0 ) { 
    r = g = b = 255 * l;
    return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
  } 
  
  if ( l < 0.5 ) t1 = l * (1.0 + s);
  else t1 = l + s - l * s;
  
  t2 = 2 * l - t1;
  tr = h + 1/3.0;
  tg = h;
  tb = h - 1/3.0;

  r = hsl_convert(tr, t1, t2);
  g = hsl_convert(tg, t1, t2);
  b = hsl_convert(tb, t1, t2);

  // NeoPixel packed RGB color
  //Serial.println("red ");
  //Serial.println(r);
  //Serial.println("green ");
  //Serial.println(g);
  //Serial.println("blue ");
  //Serial.println(b);
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}


/**
 * HSL Convert
 * Helper function
 */
uint8_t hsl_convert(float c, float t1, float t2) {

  if ( c < 0 ) c+=1; 
  else if ( c > 1 ) c-=1;

  if ( 6 * c < 1 ) c = t2 + ( t1 - t2 ) * 6 * c;
  else if ( 2 * c < 1 ) c = t1;
  else if ( 3 * c < 2 ) c = t2 + ( t1 - t2 ) * ( 2/3.0 - c ) * 6;
  else c = t2;
  
  return (uint8_t)(c*255); 
}
