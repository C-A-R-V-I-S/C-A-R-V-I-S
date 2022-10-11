#define Motor1 5
#define Motor2 6

void setup() {
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
}

void loop() {
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, LOW);
  delay(1000);
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, LOW);
  delay(1000);
}
