// 調整UNO R3板的PWM頻率

#include <PWM.h>
#define PWM_PIN 10

int pwmVal = 0;      // PWM輸出值，預設為0。
int pwmAmount = 5;   // PWM增加值
long freq = 100000L;  // PWM工作頻率設為100KHz

void setup() {
  InitTimersSafe();

  bool ok = SetPinFrequencySafe(PWM_PIN, freq); // 設置指定腳的PWM頻率
  
  if(ok) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH); 
  }
}

void loop() {
  pwmWrite(PWM_PIN, pwmVal);
  pwmVal = pwmVal + pwmAmount;

  if (pwmVal <= 0 || pwmVal > 190) {
    pwmAmount = - pwmAmount; 
  }
  
  delay(50);
}
