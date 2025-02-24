// 使用陣列變數的LED來回跑馬燈

const byte LEDs[] = {8,9,10,11,12};
const byte total = sizeof(LEDs);

void setup() {
  for (byte i=0; i<total; i++) {
    pinMode(LEDs[i], OUTPUT);  // 8~12腳設成「輸出」
    digitalWrite(LEDs[i], LOW);
  }
}

void loop() {
  for (byte i=0; i<total-1; i++) {
    digitalWrite(LEDs[i], HIGH);
    delay(100);
    digitalWrite(LEDs[i], LOW);
  }

  for (byte i=total-1; i>0; i-=1) {
    digitalWrite(LEDs[i], HIGH);
    delay(100);
    digitalWrite(LEDs[i], LOW);
  }
}
