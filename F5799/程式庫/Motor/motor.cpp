#include "motor.h"

Motor::Motor(byte ENA, byte ENB, byte IN1, byte IN2, byte IN3, byte IN4)
{
  this->ENA = ENA;
  this->ENB = ENB;
  this->IN1 = IN1;
  this->IN2 = IN2;
  this->IN3 = IN3;
  this->IN4 = IN4;

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void Motor::drive(Modes mode, int pwmA = 0, int pwmB = 0)
{
  byte _pwmA = constrain(pwmA, 0, 255);
  byte _pwmB = constrain(pwmB, 0, 255);

  // 如果模式跟之前不同，先暫停馬達…
  if (this->mode != mode)
  {
    this->mode = mode;   // 更新模式值
    analogWrite(ENA, 0); // 停止馬達
    analogWrite(ENB, 0);
    delay(200); // 暫停0.2 秒
  }

  switch (mode)
  {
  case FORWARD: // 前進
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    break;
  case BACKWARD: // 倒退
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    break;
  case LEFT: // 左轉
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    break;
  case RIGHT: // 右轉
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    break;
  case STOP: // 停止
  default:
    _pwmA = 0;
    _pwmB = 0;
    break;
  }

  analogWrite(ENA, _pwmA); // 驅動馬達
  analogWrite(ENB, _pwmB);
}
