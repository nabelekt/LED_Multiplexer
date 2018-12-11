void setup() {
  // put your setup code here, to run once:
char col1_cathode = 2;
char col2_cathode = 3;
char col3_cathode = 4;
char row1_anode = 5;
char row2_anode = 6;
char row3_anode = 7;
  pinMode(col1_cathode, OUTPUT);
  pinMode(col2_cathode, OUTPUT);
  pinMode(col3_cathode, OUTPUT);
  pinMode(row1_anode, OUTPUT);
  pinMode(row2_anode, OUTPUT);
  pinMode(row3_anode, OUTPUT);
  // turn off all GPIO pins
  digitalWrite(col1_cathode, HIGH);
  digitalWrite(col2_cathode, HIGH);
  digitalWrite(col3_cathode, HIGH);
  digitalWrite(row1_anode, HIGH);
  digitalWrite(row2_anode, HIGH);
  digitalWrite(row3_anode, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
