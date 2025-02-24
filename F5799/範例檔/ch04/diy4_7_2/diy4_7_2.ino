// 使用陣列變數的LED來回跑馬燈
// 詳細的程式說明，請參閱4-30頁。

const byte LEDs[] = {8,9,10,11,12};
const byte total = sizeof(LEDs);
uint8_t i  = 0;   // 陣列元素索引
int8_t dir = -1;  // 跑馬燈方向：1或-1

void setup() {
  for (byte i=0; i<total; i++) {
    pinMode(LEDs[i], OUTPUT);  // 8~12腳設成「輸出」
    digitalWrite(LEDs[i], LOW);
  }
}

void loop() {
  digitalWrite(LEDs[i], HIGH);
  delay(100);
  digitalWrite(LEDs[i], LOW);
  if (i == 0 || i == total-1) {
     dir = -dir;
  }
  i += dir;
}
