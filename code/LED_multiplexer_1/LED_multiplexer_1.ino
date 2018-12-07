// Code based on and heavily modified from "Transistor Multiplexing 3x3 LEDs" by Marty Peltz (https://www.instructables.com/id/Multiplexing-with-Arduino-Transistors-I-made/)

/**** variables ****/
char col1_cathode = 2;
char col2_cathode = 3;
char col3_cathode = 4;
char row1_anode = 5;
char row2_anode = 6;
char row3_anode = 7;

int max_light_level = 999;

void setup() {
  // Set Pins to outputs
  pinMode(col1_cathode, OUTPUT);
  pinMode(col2_cathode, OUTPUT);
  pinMode(col3_cathode, OUTPUT);
  pinMode(row1_anode, OUTPUT);
  pinMode(row2_anode, OUTPUT);
  pinMode(row3_anode, OUTPUT);
  // turn off all GPIO pins
  digitalWrite(col1_cathode, HIGH);
  digitalWrite(col2_cathode, LOW);
  digitalWrite(col3_cathode, LOW);
  digitalWrite(row1_anode, LOW);
  digitalWrite(row2_anode, LOW);
  digitalWrite(row3_anode, HIGH);
}

int pattern_time = 100;
void loop() {

    // pattern_F();

    // Traffic alert - pattern_time = 20
}

void pattern_A() {
  // Single light on around in a circle with center light lit
  display_LED(0x01,0x02,0x00);
  display_LED(0x02,0x02,0x00);
  display_LED(0x04,0x02,0x00);
  display_LED(0x00,0x06,0x00);
  display_LED(0x00,0x02,0x04);
  display_LED(0x00,0x02,0x02);
  display_LED(0x00,0x02,0x01);
  display_LED(0x00,0x03,0x00);
}

void pattern_B() {
  // Single light off around in a circle with center light lit
  display_LED(0x06,0x07,0x07);
  display_LED(0x05,0x07,0x07);
  display_LED(0x03,0x07,0x07);
  display_LED(0x07,0x03,0x07);
  display_LED(0x07,0x07,0x03);
  display_LED(0x07,0x07,0x05);
  display_LED(0x07,0x07,0x06);
  display_LED(0x07,0x06,0x07);
}

void pattern_C() {
  // Traffic warning signal
  display_LED(0x02,0x05,0x02);
  display_LED(0x05,0x02,0x05);
}

void pattern_D() {
  // Raining
  display_LED(0x01,0x00,0x00);
  display_LED(0x02,0x01,0x00);
  display_LED(0x04,0x02,0x01);
  display_LED(0x00,0x04,0x02);
  display_LED(0x00,0x00,0x04);
}

void pattern_E() {
  // Inverse raining
  display_LED(0x03,0x05,0x06);
  display_LED(0x07,0x03,0x05);
  display_LED(0x06,0x07,0x03);
  display_LED(0x05,0x06,0x07);
}

void pattern_F() {
  // Hold
  display_LED(0x07,0x00,0x00);
}

/**** display LED function ****/
/* Purpose: Call this function with the hexdecimal parameter you wish to display
 * Notes: This function controls the Cathode, in my case controlling the columns
 */
void display_LED(char c1, char c2, char c3)
{
    int light_level = 999;
 
  for (int i = 0; i < pattern_time; i++) {

      row_anode(c1);                   // Call row_anode with first hexdecimal value
        digitalWrite(col1_cathode, HIGH);
        delayMicroseconds(light_level);
        digitalWrite(col1_cathode, LOW);
        delayMicroseconds(max_light_level - light_level);


    row_anode(c2);                     // Call row_anode with second hexdecimal value
      digitalWrite(col2_cathode, HIGH);
      delayMicroseconds(light_level);
      digitalWrite(col2_cathode, LOW);
      delayMicroseconds(max_light_level - light_level);


      row_anode(c3);                     // Call row_anode with second hexdecimal value
      digitalWrite(col3_cathode, HIGH);
      delayMicroseconds(light_level);      
      digitalWrite(col3_cathode, LOW);
      delayMicroseconds(max_light_level - light_level);

      
  }    
}


/**** Cathode (columns) function ****/
/* Purpose: Take paramater value and turn on related pins
 * Note: Due to using Arduinos digitalWrite you must set the pins,
 *        however if using DDRx/PORTx you can just apply a hexdecimal value to set the pins on a port.
 */
void row_anode(char LEDs_on)
{
  if(LEDs_on == 0x00)
  {
    digitalWrite(row1_anode, LOW); 
    digitalWrite(row2_anode, LOW);
    digitalWrite(row3_anode, LOW);
  }
  else if(LEDs_on == 0x01)
  {
    digitalWrite(row1_anode, HIGH); 
    digitalWrite(row2_anode, LOW);
    digitalWrite(row3_anode, LOW);
  }
  else if(LEDs_on == 0x02)
  {
    digitalWrite(row1_anode, LOW); 
    digitalWrite(row2_anode, HIGH);
    digitalWrite(row3_anode, LOW); 
  }
  else if(LEDs_on == 0x03)
  {
    digitalWrite(row1_anode, HIGH); 
    digitalWrite(row2_anode, HIGH);
    digitalWrite(row3_anode, LOW); 
  }
  else if(LEDs_on == 0x04)
  {
    digitalWrite(row1_anode, LOW); 
    digitalWrite(row2_anode, LOW);
    digitalWrite(row3_anode, HIGH); 
  }
  else if(LEDs_on == 0x05)
  {
    digitalWrite(row1_anode, HIGH); 
    digitalWrite(row2_anode, LOW);
    digitalWrite(row3_anode, HIGH); 
  }
  else if(LEDs_on == 0x06)
  {
    digitalWrite(row1_anode, LOW); 
    digitalWrite(row2_anode, HIGH);
    digitalWrite(row3_anode, HIGH); 
  }
  else if(LEDs_on == 0x07)
  {
    digitalWrite(row1_anode, HIGH); 
    digitalWrite(row2_anode, HIGH);
    digitalWrite(row3_anode, HIGH); 
  }
}
