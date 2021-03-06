#include "LED_multiplexer.h"

void pattern_A() {
  // Single light on around in a circle CW with center light lit
  multiplex_LEDs(0b001, 0b010, 0b000);
  multiplex_LEDs(0b010, 0b010, 0b000);
  multiplex_LEDs(0b100, 0b010, 0b000);
  multiplex_LEDs(0b000, 0b110, 0b000);
  multiplex_LEDs(0b000, 0b010, 0b100);
  multiplex_LEDs(0b000, 0b010, 0b010);
  multiplex_LEDs(0b000, 0b010, 0b001);
  multiplex_LEDs(0b000, 0b011, 0b000);
  button_pushed = false;
}

void pattern_B() {
  // Single light on around in a circle CCW with center light lit
  multiplex_LEDs(0b001, 0b010, 0b000);
  multiplex_LEDs(0b000, 0b011, 0b000);
  multiplex_LEDs(0b000, 0b010, 0b001);
  multiplex_LEDs(0b000, 0b010, 0b010);
  multiplex_LEDs(0b000, 0b010, 0b100);
  multiplex_LEDs(0b000, 0b110, 0b000);
  multiplex_LEDs(0b100, 0b010, 0b000);
  multiplex_LEDs(0b010, 0b010, 0b000);
  button_pushed = false;
}

void pattern_C() {
  // Single light off around in a circle CW with center light lit
  multiplex_LEDs(0b110, 0b111, 0b111);
  multiplex_LEDs(0b101, 0b111, 0b111);
  multiplex_LEDs(0b011, 0b111, 0b111);
  multiplex_LEDs(0b111, 0b011, 0b111);
  multiplex_LEDs(0b111, 0b111, 0b011);
  multiplex_LEDs(0b111, 0b111, 0b101);
  multiplex_LEDs(0b111, 0b111, 0b110);
  multiplex_LEDs(0b111, 0b110, 0b111);
  button_pushed = false;
}

void pattern_D() {
  // Single light off around in a circle CCW with center light lit
  multiplex_LEDs(0b110, 0b111, 0b111);
  multiplex_LEDs(0b111, 0b110, 0b111);
  multiplex_LEDs(0b111, 0b111, 0b110);
  multiplex_LEDs(0b111, 0b111, 0b101);
  multiplex_LEDs(0b111, 0b111, 0b011);
  multiplex_LEDs(0b111, 0b011, 0b111);
  multiplex_LEDs(0b011, 0b111, 0b111);
  multiplex_LEDs(0b101, 0b111, 0b111);
  button_pushed = false;
}

void pattern_E() {
  // Traffic warning signal
  multiplex_LEDs(0b010, 0b101, 0b010);
  multiplex_LEDs(0b101, 0b010, 0b101);
  button_pushed = false;
}

void pattern_F() {
  // Raining
  multiplex_LEDs(0b001, 0b000, 0b000);
  multiplex_LEDs(0b010, 0b001, 0b000);
  multiplex_LEDs(0b100, 0b010, 0b001);
  multiplex_LEDs(0b000, 0b100, 0b010);
  multiplex_LEDs(0b000, 0b000, 0b100);
  button_pushed = false;
}

void pattern_G() {
  // Inverse raining
  multiplex_LEDs(0b011, 0b101, 0b110);
  multiplex_LEDs(0b111, 0b011, 0b101);
  multiplex_LEDs(0b110, 0b111, 0b011);
  multiplex_LEDs(0b101, 0b110, 0b111);
  button_pushed = false;
}

void pattern_H() {
  // Moving arrow
  multiplex_LEDs(0b010, 0b000, 0b000);
  multiplex_LEDs(0b111, 0b010, 0b000);
  multiplex_LEDs(0b010, 0b111, 0b010);
  multiplex_LEDs(0b010, 0b010, 0b111);
  multiplex_LEDs(0b000, 0b010, 0b010);
  multiplex_LEDs(0b000, 0b000, 0b010);
  multiplex_LEDs(0b000, 0b000, 0b000);
  button_pushed = false;
}