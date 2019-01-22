// Copied and modified from http://www.toptechboy.com/arduino/lesson-11-arduino-circuit-to-dim-led-with-potentiometer/

#define POT_PIN A5  //Declare potPin to be analog pin A0
int readValue;  // Use this variable to read Potentiometer
int writeValue; // Use this variable for writing to LED

unsigned int loop_count = 0;

void setup() {
  pinMode(POT_PIN, INPUT);  //set potPin to be an input
//  pinMode(POT_PIN, INPUT_PULLUP); 
  Serial.begin(19200);      // turn on Serial Port
  Serial.print(0);  // To freeze the lower limit
  Serial.print(1023);  // To freeze the upper limit
}
 
void loop() {
  
 readValue = analogRead(POT_PIN);  //Read the voltage on the Potentiometer
// writeValue = (255./1023.) * readValue; //Calculate Write Value for LED
 Serial.println(readValue);
// Serial.print(" ");
// Serial.println(writeValue);
 if (loop_count > 480)
    delay(50);
 loop_count++;
}
