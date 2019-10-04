// Code partially based on "Transistor Multiplexing 3x3 LEDs" by Marty Peltz (https://www.instructables.com/id/Multiplexing-with-Arduino-Transistors-I-made/)

// #include "LED_multiplexer.h"
#include <SoftwareSerial.h> // Used for printing to Serial Monitor for debug

#define COL_1_CATHODE 0  // Physical pin 13
#define ROW_1_ANODE 3  // Physical pin 10

void setup() {
  // Setup LED/transistor pins digital write pins
  pinMode(COL_1_CATHODE, OUTPUT);
  pinMode(ROW_1_ANODE, OUTPUT);
  digitalWrite(ROW_1_ANODE, HIGH);
}

void loop() {
    digitalWrite(COL_1_CATHODE, HIGH); 
    delay(1000);
    digitalWrite(COL_1_CATHODE, LOW);
    delay(1000);
}
