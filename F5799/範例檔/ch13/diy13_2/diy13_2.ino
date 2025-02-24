// 自動迴避障礙物的自走車

#include <hcsr05.h>
#include <motor.h>

HCSR05 sr05(13, 12); // trig, echo
// Motor (ENA, ENB, IN1, IN2, IN3, IN4)
Motor motor(5, 6, 7, 8, 10, 9);

const byte pwm = 200;   // 馬達的 PWM 輸出值
int thresh = 10; // 10cm
long distance;            // 暫存接收訊號的高電位持續時間

void setup() { }

void loop() {
  distance = sr05.ping(); // 讀取障礙物的距離

  // 如果距離大於 10cm...
  if (distance > thresh) {
    motor.drive(FORWARD, pwm, pwm);  // 前進
  } else {
    motor.drive(RIGHT, pwm, pwm);  // 右轉
  }
  delay(500);
}
