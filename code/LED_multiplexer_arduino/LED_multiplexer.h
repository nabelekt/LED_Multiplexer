#pragma once // Prevent cyclic inclusion
#include <stdbool.h>

bool button_pushed;

void multiplex_LEDs(int, int, int);
bool update_rows(int);
void check_button();
int map_speed_value(int);
int map_brightness_value(int);

void pattern_A();
void pattern_B();
void pattern_C();
void pattern_D();
void pattern_E();
void pattern_F();
void pattern_G();
void pattern_H();