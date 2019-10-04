// Code partially based on "Transistor Multiplexing 3x3 LEDs" by Marty Peltz (https://www.instructables.com/id/Multiplexing-with-Arduino-Transistors-I-made/)

// #include "LED_multiplexer.h"
#include <SoftwareSerial.h> // Used for printing to Serial Monitor for debug

#define COL_1_CATHODE 0  // Physical pin 13
#define COL_2_CATHODE 1  // Physical pin 12
#define COL_3_CATHODE 2  // Physical pin 11
#define ROW_1_ANODE 3  // Physical pin 10
#define ROW_2_ANODE 4  // Physical pin 9
#define ROW_3_ANODE 5  // Physical pin 8
#define BRIGHTNESS_POT_PIN A6   // Physical pin 7
#define SPEED_POT_PIN A7  // Physical pin 6

#define LIGHT_LEVEL_INIT 1000
#define MAX_BRIGHTNESS 1000
#define PATTERN_TIME_INIT 100

// Setup pattern function pointers
int brightness = LIGHT_LEVEL_INIT;
int pattern_time = PATTERN_TIME_INIT;


// Setup serial monitor
// SoftwareSerial Monitor(9, 10);

void setup() {
  // Setup serial monitor
//  Monitor.begin(9600);
//  pinMode(10, OUTPUT);
//  pinMode(9, INPUT);

  // Setup LED/transistor pins digital write pins
  pinMode(COL_1_CATHODE, OUTPUT);
  pinMode(COL_2_CATHODE, OUTPUT);
  pinMode(COL_3_CATHODE, OUTPUT);
  pinMode(ROW_1_ANODE, OUTPUT);
  pinMode(ROW_2_ANODE, OUTPUT);
  pinMode(ROW_3_ANODE, OUTPUT);
  digitalWrite(COL_1_CATHODE, LOW);
  digitalWrite(COL_2_CATHODE, LOW);
  digitalWrite(COL_3_CATHODE, LOW);
  digitalWrite(ROW_1_ANODE, LOW);
  digitalWrite(ROW_2_ANODE, LOW);
  digitalWrite(ROW_3_ANODE, LOW);
  
  // Setup potentiometer analog read pins
//  pinMode(SPEED_POT_PIN, INPUT);
//  pinMode(BRIGHTNESS_POT_PIN, INPUT);
}

void loop() {
  multiplex_LEDs(0b001, 0b010, 0b000);
  multiplex_LEDs(0b010, 0b010, 0b000);
}

void multiplex_LEDs(int col_1, int col_2, int col_3)
{
  for (int i = 0; i < pattern_time; i++) {
    update_rows(col_1);
    digitalWrite(COL_1_CATHODE, HIGH);
    delayMicroseconds(brightness);
    digitalWrite(COL_1_CATHODE, LOW);
    // delayMicroseconds(MAX_BRIGHTNESS - brightness);

    update_rows(col_2);
    digitalWrite(COL_2_CATHODE, HIGH);
    delayMicroseconds(brightness);
    digitalWrite(COL_2_CATHODE, LOW);
    // delayMicroseconds(MAX_BRIGHTNESS - brightness);

    update_rows(col_3);
    digitalWrite(COL_3_CATHODE, HIGH);
    delayMicroseconds(brightness);      
    digitalWrite(COL_3_CATHODE, LOW);
    // delayMicroseconds(MAX_BRIGHTNESS - brightness);
  }    
}

void update_rows(int LED_vals)
{

  switch (LED_vals) {
    case 0x00:
      digitalWrite(ROW_1_ANODE, LOW); 
      digitalWrite(ROW_2_ANODE, LOW);
      digitalWrite(ROW_3_ANODE, LOW);
      break;
    case 0x01:
      digitalWrite(ROW_1_ANODE, LOW); 
      digitalWrite(ROW_2_ANODE, LOW);
      digitalWrite(ROW_3_ANODE, HIGH);
      break;
    case 0x02:
      digitalWrite(ROW_1_ANODE, LOW); 
      digitalWrite(ROW_2_ANODE, HIGH);
      digitalWrite(ROW_3_ANODE, LOW); 
      break;
    case 0x03:
      digitalWrite(ROW_1_ANODE, LOW); 
      digitalWrite(ROW_2_ANODE, HIGH);
      digitalWrite(ROW_3_ANODE, HIGH); 
      break;
    case 0x04:
      digitalWrite(ROW_1_ANODE, HIGH); 
      digitalWrite(ROW_2_ANODE, LOW);
      digitalWrite(ROW_3_ANODE, LOW); 
      break;
    case 0x05:
      digitalWrite(ROW_1_ANODE, HIGH); 
      digitalWrite(ROW_2_ANODE, LOW);
      digitalWrite(ROW_3_ANODE, HIGH); 
      break;
    case 0x06:
      digitalWrite(ROW_1_ANODE, HIGH); 
      digitalWrite(ROW_2_ANODE, HIGH);
      digitalWrite(ROW_3_ANODE, LOW); 
      break;
    case 0x07:
      digitalWrite(ROW_1_ANODE, HIGH); 
      digitalWrite(ROW_2_ANODE, HIGH);
      digitalWrite(ROW_3_ANODE, HIGH);
      break;
  }
}
