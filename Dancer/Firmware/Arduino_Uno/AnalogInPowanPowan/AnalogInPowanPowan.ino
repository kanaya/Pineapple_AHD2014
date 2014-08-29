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

 
#define RESOLUTION 200
#define PIN13 13

int TH = 200;

int ledPin0 = 3;    // LED connected to digital pin 9
int sensorPin0 = A0;

int powanDelay = 50;  // ms
int loopDelay = 10;  // ms
int sleepDelay = 2000;  // ms

int sensorValue0 = 0;

int brightnessTable[RESOLUTION];

void setup()  { 
  pinMode(ledPin0, OUTPUT);
  pinMode(sensorPin0, INPUT);
  
  pinMode(PIN13, OUTPUT);
  
  for (int i = 0; i < RESOLUTION; ++i) {
    brightnessTable[i] = (int)(255.0 * pow(((-cos((double)i / (double)RESOLUTION * 2.0 * 3.14159) + 1.0) / 2.0), 2.2));
  }
} 

void loop()  {
  sensorValue0 = analogRead(sensorPin0);
  if (sensorValue0 > TH) {
    digitalWrite(13, HIGH);
    for(int i = 0; i < RESOLUTION; ++i) {
      analogWrite(ledPin0, brightnessTable[i]);       
      delay(powanDelay);                           
     }
     digitalWrite(PIN13, LOW);
     delay(sleepDelay);
  }
  delay(loopDelay);
}


