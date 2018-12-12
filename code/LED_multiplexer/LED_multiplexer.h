#pragma once // Prevent cyclic inclusion

void multiplex_LEDs(int, int, int);
void update_rows(int);

void pattern_A();
void pattern_B();
void pattern_C();
void pattern_D();
void pattern_E();
void pattern_F();
void pattern_G();

void (*patterns[7]) (void);