// Code partially based on "Transistor Multiplexing 3x3 LEDs" by Marty Peltz (https://www.instructables.com/id/Multiplexing-with-Arduino-Transistors-I-made/)

#include "LED_multiplexer.h"
#include "patterns.c"
#include <math.h>
#include <SoftwareSerial.h> // Used for printing to Serial Monitor for debug

#define COL_1_CATHODE 0  // Physical pin 13
#define COL_2_CATHODE 1  // Physical pin 12
#define COL_3_CATHODE 2  // Physical pin 11
#define ROW_1_ANODE 3  // Physical pin 10
#define ROW_2_ANODE 4  // Physical pin 9
#define ROW_3_ANODE 5  // Physical pin 8
#define BUTTON_PIN 8  // Physical pin 5
#define BRIGHTNESS_POT_PIN A6   // Physical pin 7
#define SPEED_POT_PIN A7  // Physical pin 6

#define LIGHT_LEVEL_INIT 100
#define MAX_BRIGHTNESS 1000
#define PATTERN_TIME_INIT 20

#define NUM_PATTERNS 8

// Setup pattern function pointers
void (*patterns[NUM_PATTERNS])(void) = 
  {&pattern_A, &pattern_B, &pattern_C, &pattern_D, &pattern_E,
   &pattern_F, &pattern_G, &pattern_H};

int pattern_ind = 0;
int brightness = LIGHT_LEVEL_INIT;
int pattern_time = PATTERN_TIME_INIT;


// Setup serial monitor
SoftwareSerial Monitor(9, 10);

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
  pinMode(SPEED_POT_PIN, INPUT);
  pinMode(BRIGHTNESS_POT_PIN, INPUT);
  
  // Setup button digital read pin
  pinMode(BUTTON_PIN, INPUT);

  button_pushed = false;
}

void loop() {
  patterns[pattern_ind]();  // Run selected pattern
}

void multiplex_LEDs(int col_1, int col_2, int col_3)
{
  // Function should be improved by using clock time rather than iteration count for pattern_time
  // Making this improvement would prevent change in brightness from effecting speed
  for (int i = 0; i < pattern_time; i++) {
    if (update_rows(col_1))
      return;
    digitalWrite(COL_1_CATHODE, HIGH);
    delayMicroseconds(brightness);
    digitalWrite(COL_1_CATHODE, LOW);
    delayMicroseconds(MAX_BRIGHTNESS - brightness);

    if (update_rows(col_2))
      return;
    digitalWrite(COL_2_CATHODE, HIGH);
    delayMicroseconds(brightness);
    digitalWrite(COL_2_CATHODE, LOW);
    delayMicroseconds(MAX_BRIGHTNESS - brightness);

    if (update_rows(col_3))
      return;
    digitalWrite(COL_3_CATHODE, HIGH);
    delayMicroseconds(brightness);      
    digitalWrite(COL_3_CATHODE, LOW);
    delayMicroseconds(MAX_BRIGHTNESS - brightness);

    pattern_time = map_speed_value(analogRead(SPEED_POT_PIN));
    brightness = map_brightness_value(analogRead(BRIGHTNESS_POT_PIN));
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

int map_speed_value(int speed_pot_val){
  int speed_val = round(1.703*pow(M_E, 0.0055*(-speed_pot_val+1023)))-1;
  return speed_val;
}

int map_brightness_value(int brightness_pot_val){
  int brightness_val = round((float)brightness_pot_val/1023*MAX_BRIGHTNESS);
  return brightness_val;
}
