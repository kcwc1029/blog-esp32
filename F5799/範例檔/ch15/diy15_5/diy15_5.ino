// 循跡自走車範例

#include <motor.h>

const byte IR_PINS[] = {11, 12, 13}; // 右中左
const byte NUM_OF_IR = sizeof(IR_PINS);

// Motor (ENA, ENB, IN1, IN2, IN3, IN4)
Motor motor(5, 6, 7, 8, 10, 9);

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
      motor.drive(FORWARD, 40, 40);
      break;
    case 1: // 小幅左轉，右60左30
      motor.drive(LEFT, 60, 30);
      break;
    case 3: // 大幅左轉，右90左25
      motor.drive(LEFT, 90, 25);
      break;
    case 4: // 小幅右轉，右30左60
      motor.drive(RIGHT, 30, 60);
      break;
    case 6: // 大幅右轉，右25左90
      motor.drive(RIGHT, 25, 90);
      break;
    default: // 停止
      motor.drive(STOP);
      break;
  }
}
