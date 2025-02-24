// 加入數位濾波的伺服馬達雲台程式

#include <Servo.h>
#define size 5         // 資料陣列元素數量
#define middle size/2  // 資料陣列中間索引
#define IN_X A0        // 可變電阻X（水平搖桿）的輸入腳
#define IN_Y A1        // 可變電阻Y（垂直搖桿）的輸入腳
#define OUT_X 5        // 伺服馬達X的輸出腳
#define OUT_Y 6        // 伺服馬達Y的輸出腳

Servo servoX, servoY;   // 宣告兩個伺服馬達程式物件

int valX[size] = {0, 0, 0, 0, 0};  // X軸資料陣列
int valY[size] = {0, 0, 0, 0, 0};  // Y軸資料陣列

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void filter() {
  static byte i = 0;  // 陣列索引

  valX[i] = analogRead(IN_X);  // 水平（X）搖桿的輸入值
  valY[i] = analogRead(IN_Y);  // 垂直（Y）搖桿的輸入值  

  qsort(valX, size, sizeof(int), cmp);
  qsort(valY, size, sizeof(int), cmp);

  if (++i % size == 0) i = 0;
}

void control() {
   int posX, posY;

   posX = map(valX[middle], 0, 1023, 0, 180);
   posY = map(valY[middle], 0, 1023, 0, 180);
 
   servoX.write(posX);
   servoY.write(posY);

   delay(15);
}

void setup() {
  servoX.attach(OUT_X, 500, 2400);
  servoY.attach(OUT_Y, 500, 2400);
}

void loop() {
   filter();
   control(); 
}
