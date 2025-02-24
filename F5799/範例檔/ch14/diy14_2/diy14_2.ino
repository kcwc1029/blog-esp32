#include <Servo.h>

Servo servoX, servoY;   // 宣告兩個伺服馬達程式物件
    
const byte pinX = A0;    // 宣告可變電阻的輸入端子
const byte pinY = A1;

int valX, posX;       // 暫存類比輸入值的變數
int valY, posY;

void setup() {
  servoX.attach(5, 500, 2400);    // 設定伺服馬達的接腳
  servoY.attach(6, 500, 2400);
}

void loop() {
   valX = analogRead(pinX);     // 讀取可變電阻（搖桿）的輸入值
   valY = analogRead(pinY);   

   // 將類比輸入值0~1023，對應成伺服馬達的0~180度。
   posX = map(valX, 0, 1023, 0, 180);
   posY = map(valY, 0, 1023, 0, 180);
 
   servoX.write(posX);    // 設定伺服馬達的旋轉角度
   servoY.write(posY); 

   delay(15);             // 延遲一段時間，讓伺服馬達轉到定位。
}
