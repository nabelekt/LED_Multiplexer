// Code partially based on "Transistor Multiplexing 3x3 LEDs" by Marty Peltz (https://www.instructables.com/id/Multiplexing-with-Arduino-Transistors-I-made/)

#include "LED_multiplexer.h"
#include "patterns.c"

#define COL_1_CATHODE 2
#define COL_2_CATHODE 3
#define COL_3_CATHODE 4
#define ROW_1_ANODE 5
#define ROW_2_ANODE 6
#define ROW_3_ANODE 7

#define LIGHT_LEVEL_INIT 1
#define MAX_LIGHT_LEVEL 999
#define PATTERN_TIME_INIT 10

#define NUM_PATTERNS 7

void setup() {
  // Setup pins
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

  // Setup pattern function pointers
  void (*patterns[NUM_PATTERNS])(void) = 
    {&pattern_A, &pattern_B, &pattern_C, &pattern_D, &pattern_E, &pattern_F, &pattern_G};
}

void loop() {
  // Loop through patterns running each pattern 5 times in a row
  for (int pattern_ind = 0; pattern_ind < NUM_PATTERNS; pattern_ind++)
    for (int count = 0; count < 5; count++)
      patterns[pattern_ind];  // Run selected pattern
}

void multiplex_LEDs(int col_1, int col_2, int col_3)
{
  int light_level = LIGHT_LEVEL_INIT;
  int pattern_time = PATTERN_TIME_INIT;
 
  for (int i = 0; i < pattern_time; i++) {

    update_rows(col_1);
    digitalWrite(COL_1_CATHODE, HIGH);
    delayMicroseconds(light_level);
    digitalWrite(COL_1_CATHODE, LOW);
    delayMicroseconds(MAX_LIGHT_LEVEL - light_level);


    update_rows(col_2);
    digitalWrite(COL_2_CATHODE, HIGH);
    delayMicroseconds(light_level);
    digitalWrite(COL_2_CATHODE, LOW);
    delayMicroseconds(MAX_LIGHT_LEVEL - light_level);


    update_rows(col_3);
    digitalWrite(COL_3_CATHODE, HIGH);
    delayMicroseconds(light_level);      
    digitalWrite(COL_3_CATHODE, LOW);
    delayMicroseconds(MAX_LIGHT_LEVEL - light_level);
      
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
