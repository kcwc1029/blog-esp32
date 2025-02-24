// 控制UNO R4 Minima的TX和RX LED燈

bool flag = true;

void setup() {
  pinMode(LED_TX, OUTPUT);   // TX腳（21）設成「輸出」模式
  pinMode(LED_RX, OUTPUT);   // RX腳（22）設成「輸出」模式
}

void loop() {
  if (flag) {
    digitalWrite(LED_TX, HIGH);
    digitalWrite(LED_RX,  LOW);
  } else {
    digitalWrite(LED_TX,  LOW);
    digitalWrite(LED_RX, HIGH);
  }

  flag = !flag;
  delay(500);
}
