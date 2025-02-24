// 在LED點陣繪製圖像

#include <ArduinoGraphics.h>     // 先引用「Arduino圖像」程式庫
#include <Arduino_LED_Matrix.h>  // 再引用LED點陣程式庫

ArduinoLEDMatrix matrix;  // 宣告LED點陣物件

void drawRect() {  // 繪製矩形和直線的自訂函式
  matrix.beginDraw();  // 開始繪製
  matrix.stroke(0xffffff);  // 設定畫筆：點亮LED
  matrix.rect(0, 0, matrix.width(), matrix.height());  // 矩形(0, 0, 畫布寬, 畫布高)
  matrix.line(0, 0, matrix.width() - 1, matrix.height() - 1); // 直線(0, 0, 寬-1, 高-1)
  matrix.endDraw();  // 結束繪製
}

void drawText() {  // 繪製文字的自訂函式
  matrix.beginDraw();  // 開始繪製
  matrix.stroke(0xffffff); // 設定畫筆：點亮LED
  matrix.textFont(Font_5x7);  // 選用5x7大小的字體
  matrix.text("GO", 2, 1);     // 在(2, 1)座標呈現“GO”
  matrix.endDraw();  // 結束繪製
}

void drawBlank() {   // 繪製空白畫面
  matrix.beginDraw(); // 開始繪製
  matrix.noStroke();  // 沒有畫筆
  matrix.fill(0);      // 填入黑色（熄滅LED）
  matrix.rect(0, 0, matrix.width(), matrix.height());  // 矩形(0, 0, 畫布寬, 畫布高)
  matrix.endDraw(); // 結束繪製
}

void setup() {
  matrix.begin();  // 初始化LED點陣
}

void loop() {
  drawRect();  // 繪製矩形
  delay(3000);
  drawBlank(); // 繪製空白畫面
  drawText();  // 繪製文字訊息
  delay(3000);
  drawBlank(); // 繪製空白畫面
}
