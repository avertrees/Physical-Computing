///BME Includes
#include <Adafruit_BME280.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//BME VARIABLES
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

float minTemp, tempCelc, tempFar;

//LED VARAIBLES
//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

int num = 8; //global number of LEDs for loops to access
int leds[8] = {2, 3, 4, 5, 6, 7, 8, 9}; //array of LEDs for ref                       

unsigned long delayTime;

void setup() {

    //BME
    Serial.begin(9600);
    Serial.println(F("BME280 test"));

    bool status;
    
    // default settings
    // (you can also pass in a Wire library object like &Wire2)
    status = bme.begin();  
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
    
    Serial.println("-- Default Test --");
    delayTime = 1000;

    Serial.println();

    for(int i = 0; i <= 8; i++){
      pinMode(leds[i], OUTPUT);
    }
}


void loop() { 
    //BME
    tempCelc = bme.readTemperature();
    tempFar = (bme.readTemperature() * (1.8)) + 32;

    int ledIndex = (int)tempFar/10;

    for(int i = 0; i<= ledIndex; i++){
      
      digitalWrite(leds[i], HIGH);   // turn the LED on (HIGH is the voltage level)

    }
    
    
    printValues();
    delay(delayTime);

    for(int i = 0; i<= ledIndex; i++){
      
      digitalWrite(leds[i], LOW);   // turn the LED on (HIGH is the voltage level)

    }
    
    printValues();
    //delay(delayTime);
    delay(delayTime);   
}

void printValues() {
    Serial.println();
    //Print degrees celcius 
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    //Serial.println();
    
    //print degrees fahrenheit 
    Serial.print("Temperature = ");
    Serial.print(tempFar);
    Serial.println(" *F");
    Serial.println();
    
    /*
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
    */
}


