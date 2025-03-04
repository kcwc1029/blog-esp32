#include <ESP32Servo.h>

Servo myServo;
const byte servoPin = 33;
const byte VR = 32;  // 可變電阻接腳

void setup() {
  pinMode(VR, INPUT);
  myServo.attach(servoPin, 500, 2500);
}

void loop() {
  int val = analogRead(VR);  // 讀取電阻數值 (0~4095)
  val = map(val, 0, 4095, 0, 180); // 轉換為 0~180°
  myServo.write(val);  // 設定伺服馬達角度
  delay(15);
}
