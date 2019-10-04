#include <math.h>

#define LED_PIN A7
#define SPEED_POT_PIN A1

#define PATTERN_TIME_INIT 200

int delay_val = PATTERN_TIME_INIT;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  // Setup potentiometer analog read pins
  pinMode(SPEED_POT_PIN, INPUT);
}

void loop() {
//    delay_val = map_speed_value(analogRead(SPEED_POT_PIN));
    delay_val = analogRead(SPEED_POT_PIN);
    digitalWrite(LED_PIN, HIGH);
    delay(delay_val);
    digitalWrite(LED_PIN, LOW);
    delay(delay_val);
}


//int map_speed_value(int speed_pot_val){
//  int speed_val = round(1.703*pow(M_E, 0.0055*speed_pot_val))-1;
//  return speed_val;
//}
