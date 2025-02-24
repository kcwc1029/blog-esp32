#ifndef HCSR05_H
#define HCSR05_H
#include <Arduino.h>

class HCSR05 {
  private:
    byte trig;  // 超音波模組的觸發腳
    byte echo;   // 超音波模組的接收腳

  public:
    HCSR05(byte trigPin, byte echoPin);
    float ping();
};

int ping();
#endif // HCSR05_H
