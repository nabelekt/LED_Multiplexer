
#define COL_1_CATHODE 0  // Physical pin 13
#define COL_2_CATHODE 1  // Physical pin 12
#define COL_3_CATHODE 2  // Physical pin 11
#define ROW_1_ANODE 3  // Physical pin 10
#define ROW_2_ANODE 4  // Physical pin 9
#define ROW_3_ANODE 5  // Physical pin 8

void setup() {

  pinMode(COL_1_CATHODE, OUTPUT);
  pinMode(COL_2_CATHODE, OUTPUT);
  pinMode(COL_3_CATHODE, OUTPUT);
  pinMode(ROW_1_ANODE, OUTPUT);
  pinMode(ROW_2_ANODE, OUTPUT);
  pinMode(ROW_3_ANODE, OUTPUT);

  digitalWrite(COL_1_CATHODE, HIGH);
  digitalWrite(COL_2_CATHODE, HIGH);
  digitalWrite(COL_3_CATHODE, HIGH);
  digitalWrite(ROW_1_ANODE, HIGH);
  digitalWrite(ROW_2_ANODE, HIGH);
  digitalWrite(ROW_3_ANODE, HIGH);
  
}

void loop() {

}
