/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */
 
#define RESOLUTION 100

int ledPin = 3;    // LED connected to digital pin 9

int brightnessTable[RESOLUTION];

void setup()  { 
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  
  for (int i = 0; i < RESOLUTION; ++i) {
    brightnessTable[i] = (int)(255.0 * (cos((double)i / (double)RESOLUTION * 2.0 * 3.14159) + 1.0) / 2.0);
  }
} 

void loop()  { 
  // fade in from min to max in increments of 5 points:
  for(int i = 0; i < RESOLUTION; ++i) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, brightnessTable[i]);       
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                           
  } 
}


