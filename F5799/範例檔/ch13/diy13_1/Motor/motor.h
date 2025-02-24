#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

typedef enum {
  FORWARD, BACKWARD, LEFT, RIGHT, STOP
} Modes;

class Motor {
  byte ENA, ENB, IN1, IN2, IN3, IN4;
  Modes mode = STOP;
  
  public:
    Motor (byte ENA, byte ENB, byte IN1, byte IN2, byte IN3, byte IN4);
    void drive(Modes mode, int pwmA=0, int pwmB=0);
};
#endif // MOTOR_H
