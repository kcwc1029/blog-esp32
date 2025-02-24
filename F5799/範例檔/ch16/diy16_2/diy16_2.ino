#include <SoftwareSerial.h>    // 引用「軟體序列埠」程式庫
#include <motor.h>

SoftwareSerial BT(3, 2);       // 設定軟體序列埠(接收腳, 傳送腳)
Motor motor(5, 6, 7, 8, 10, 9);   // 設定馬達

char command;            // 接收序列埠值的變數
// 設定PWM輸出值（註：FA-130馬達供電不要超過3v）
// 計算方式：(3v / 5v) X 255 = 153，最高不要超過153。
const byte pwm = 130; 

void setup() {
  BT.begin(9600);            // 啟動軟體序列埠
  motor.drive(STOP);
}

void loop() {
  if (BT.available() > 0) {
    command = BT.read();

    switch (command) {
    case  'w' :     // 接收到 'w'，前進
      motor.drive(FORWARD, pwm, pwm);
      break;
    case  'x' :     // 接收到 'x'，後退
      motor.drive(BACKWARD, pwm, pwm);
      break;
    case  'a' :     // 接收到 'a'，左轉
      motor.drive(LEFT, pwm, pwm);
      break;
    case  'd' :     // 接收到 'd'，右轉
      motor.drive(RIGHT, pwm, pwm);
      break;
    case  's' :     // 接收到 's'，停止馬達
    default:
      motor.drive(STOP);
    }
  }
}
