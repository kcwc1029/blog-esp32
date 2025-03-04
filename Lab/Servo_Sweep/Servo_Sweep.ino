#include <ESP32Servo.h> // 引入伺服馬達函式庫

Servo myServo;         // 建立伺服馬達物件

const byte servoPin = 33;  // 伺服馬達信號接 GPIO 33

void setup() {
  myServo.attach(servoPin, 500, 2500); // 設定 PWM 範圍
}

void loop() {
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);  // 讓伺服馬達轉到指定角度
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
}
