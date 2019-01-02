// Code partially based on "Transistor Multiplexing 3x3 LEDs" by Marty Peltz (https://www.instructables.com/id/Multiplexing-with-Arduino-Transistors-I-made/)

#include "LED_multiplexer.h"
#include "patterns.c"
// #include <Serial.h>

#define COL_1_CATHODE 2
#define COL_2_CATHODE 3
#define COL_3_CATHODE 4
#define ROW_1_ANODE 5
#define ROW_2_ANODE 6
#define ROW_3_ANODE 7
#define BUTTON_PIN 8

#define LIGHT_LEVEL_INIT 100
#define MAX_LIGHT_LEVEL 999
#define PATTERN_TIME_INIT 20

#define NUM_PATTERNS 7

// Setup pattern function pointers
void (*patterns[NUM_PATTERNS])(void) = 
  {&pattern_A, &pattern_B, &pattern_C, &pattern_D, &pattern_E, &pattern_F, &pattern_G};

int pattern_ind = 0;
int light_level = LIGHT_LEVEL_INIT;

void setup() {
  Serial.begin(9600);

  // Setup LED/transistor pins
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

  // Setup other pins
  digitalWrite(BUTTON_PIN, INPUT);

  button_pushed = false;
}

void loop() {
  patterns[pattern_ind]();  // Run selected pattern
  Serial.println(pattern_ind);
}

void multiplex_LEDs(int col_1, int col_2, int col_3)
{
  int light_level = LIGHT_LEVEL_INIT;
  int pattern_time = PATTERN_TIME_INIT;
 
  for (int i = 0; i < pattern_time; i++) {
    if (update_rows(col_1))
      return;
    digitalWrite(COL_1_CATHODE, HIGH);
    delayMicroseconds(light_level);
    digitalWrite(COL_1_CATHODE, LOW);
    delayMicroseconds(MAX_LIGHT_LEVEL - light_level);

    if (update_rows(col_2))
      return;
    digitalWrite(COL_2_CATHODE, HIGH);
    delayMicroseconds(light_level);
    digitalWrite(COL_2_CATHODE, LOW);
    delayMicroseconds(MAX_LIGHT_LEVEL - light_level);

    if (update_rows(col_3))
      return;
    digitalWrite(COL_3_CATHODE, HIGH);
    delayMicroseconds(light_level);      
    digitalWrite(COL_3_CATHODE, LOW);
    delayMicroseconds(MAX_LIGHT_LEVEL - light_level);
  }    
}

bool update_rows(int LED_vals)
{
  if (!button_pushed)
    check_button();
  if (button_pushed)  // Return right away if button was pushed.
    return true;

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

  return false;
}

void check_button() {
  if (digitalRead(BUTTON_PIN)) { // If button is pushed
    // Turn all lights off except center light while handling button press
    digitalWrite(ROW_1_ANODE, LOW);
    digitalWrite(ROW_2_ANODE, HIGH);
    digitalWrite(COL_2_CATHODE, HIGH);
    digitalWrite(ROW_3_ANODE, LOW);

    if (!button_pushed) {
      pattern_ind++;
      if (pattern_ind >= NUM_PATTERNS)
        pattern_ind = 0;
      button_pushed = true;
    }
    delay(200); // Ignore button push within same 1/5 second
  }
}
