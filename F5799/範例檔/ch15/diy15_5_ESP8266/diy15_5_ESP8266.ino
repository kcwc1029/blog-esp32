// 使用Wemos D1 mini板（ESP8266）
// 搭配Wemos官方的Motor馬達控制板
// 馬達控制板程式庫下載：https://docs.wemos.cc/en/latest/d1_mini_shiled/motor.html

#include "WEMOS_Motor.h"

const byte IR_PINS[] = {D0, D5, D6}; // 右中左
const byte NUM_OF_IR = sizeof(IR_PINS);

// 馬達驅動板的I2C位址：0x30、PWM頻率：1000Hz
Motor motorL(0x30, _MOTOR_A, 1000);
Motor motorR(0x30, _MOTOR_B, 1000);

// 之前的感測狀態
byte prevIR = 0;

byte checkIR() {
  byte IR = 0;

  for (byte i = 0; i < NUM_OF_IR; i++) {
    byte val = digitalRead(IR_PINS[i]) << i;
    IR = IR | val;
  }
  return IR;
}

void setup() {
  // 所有循跡感測器接腳都設成「輸入」模式
  for (byte i = 0; i < NUM_OF_IR; i++) {
    pinMode(IR_PINS[i], INPUT);
  }
}

void loop() {
  byte IR = checkIR();

  if (IR == 7) {
    IR = prevIR;
  } else {
    prevIR = IR;
  }

  switch (IR) {
    case 0:
    case 5: // 直行
      motorR.setmotor(_CW, 40);
      motorL.setmotor(_CW, 40);
      break;
    case 1: // 小幅左轉
      motorR.setmotor(_CW, 60);
      motorL.setmotor(_CW, 30);
      break;
    case 3: // 大幅左轉
      motorR.setmotor(_CW, 90);
      motorL.setmotor(_CW, 25);
      break;
    case 4: // 小幅右轉
      motorR.setmotor(_CW, 30);
      motorL.setmotor(_CW, 60);
      break;
    case 6: // 大幅右轉
      motorR.setmotor(_CW, 25);
      motorL.setmotor(_CW, 90);
      break;
    default: // 停止
      motorR.setmotor(_STOP);
      motorL.setmotor(_STOP);
      break;
  }
}
