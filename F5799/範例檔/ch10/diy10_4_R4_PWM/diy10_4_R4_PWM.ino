// 調整UNO R4板的PWM頻率

#include <pwm.h>  // 引用此程式庫

PwmOut pwm9(9);   // 宣告PwmOut物件，名叫pwm9，對應接腳9。
PwmOut pwm10(10);
PwmOut pwm11(11);

void setup() {
  pwm9.begin(50, 10);    // 週期 50us = 20kHz、脈衝寬 10us = 20%
  pwm10.begin(10000.0, 25.0);   // 10kHz頻率、25%工作週期
  pwm11.begin(1000.0, 0.0);     // 1kHz頻率、0%工作週期
  pwm11.pulse_perc(50.0);    // 工作週期改成50%
}

void loop() {}