// 用麵包板組裝開關電路
const byte LED = 13;
const byte SW = 8;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
}
void loop() {
  bool val = digitalRead(SW);
  digitalWrite(LED, val);
}
