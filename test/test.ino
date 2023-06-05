void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(12, INPUT);
  pinMode(16, INPUT_PULLUP);
}


void loop() {

  digitalWrite(0 , !digitalRead(12));
  digitalWrite(2 , !digitalRead(16));
  Serial.print("14");
  Serial.print(digitalRead(12));
  Serial.print("16");
  Serial.println(digitalRead(16));
}
