#include <Servo.h>
#define SW_PIN 7      // 開關接腳
#define SERVO_PIN 8   // 伺服馬達接腳

Servo servo;   // 宣告伺服馬達物件

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP);   // 啟用開關接腳的上拉電阻
  servo.attach(SERVO_PIN, 500, 2400);  // 設定伺服馬達物件
  servo.write(90);            // 伺服馬達轉到90度
}

void loop() {
  bool sw = digitalRead(SW_PIN);  // 讀取按鍵輸入

  if (sw == 0) {      // 若開關被按下…
    servo.write(150);
    delay(2000);
    servo.write(90);
    delay(1000);
  }
}
