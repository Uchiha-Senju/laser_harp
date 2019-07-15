/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

#include "pitches.h"
int notes[] = {50,250,450,550}; // Set notes C, D, E, F, G, A, B

int l1 = A0;
int l2 = A1;
int l3 = A2;
int l4 = A3;
int sensor1Value = 0;
int sensor2Value = 0;
int sensor3Value = 0;
int sensor4Value = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  sensor1Value = analogRead(l1);
  sensor2Value = analogRead(l2);
  sensor3Value = analogRead(l3);
  sensor4Value = analogRead(l4);
  if (sensor1Value >= 300)
  {
    tone(8, notes[0]); // C
  }
  else if (sensor2Value >= 300) 
  {
    tone(8, notes[1]); // D
  }
  else if (sensor3Value >= 300) 
  {
    tone(8, notes[2]); // E
  }
  else if (sensor4Value >= 300) 
  {
    tone(8, notes[3]); // F
  }
  else
  { 
    noTone(8);
  } // e
  Serial.println(sensor1Value);
  Serial.println(sensor2Value);
  Serial.println(sensor3Value);
  Serial.println(sensor4Value);
  Serial.println(" ");
  delay(100);
}
