// 跑馬燈範例程式二：使用for迴圈

const byte startPin = 8;
const byte endPin = 12;
byte lightPin = startPin;

void setup() {
  for (byte i = startPin; i <= endPin; i++) {
    pinMode(i, OUTPUT);   // 接腳模式設成「輸出」
    digitalWrite(i, LOW);   // 輸出「低電位」（關閉LED）
  }
}

void loop() {
  digitalWrite(lightPin, HIGH);
  delay(100);
  digitalWrite(lightPin, LOW);

  if (lightPin < endPin) {
    lightPin ++;
  } else {
    lightPin = startPin;
  }
}
