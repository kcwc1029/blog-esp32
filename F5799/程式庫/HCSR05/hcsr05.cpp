#include "hcsr05.h"

HCSR05::HCSR05(byte trigPin, byte echoPin) {
  trig = trigPin;
  echo = echoPin;

  pinMode(trig, OUTPUT); // 觸發腳設定成「輸出」
  pinMode(echo, INPUT); // 接收腳設定成「輸入」
}

float HCSR05::ping() { // 超音波感測程式
  unsigned long d;
  digitalWrite(trig, HIGH);   // 觸發腳設定成高電位
  delayMicroseconds(10);      // 持續 10 微秒
  digitalWrite(trig, LOW);    // 觸發腳設定成低電位
  d = pulseIn(echo, HIGH, 23000); // 測量高電位的持續時間（μs ）

  return d / 58.0;  // 傳回公分單位的距離
}

int ping() {
  return 168;
}
