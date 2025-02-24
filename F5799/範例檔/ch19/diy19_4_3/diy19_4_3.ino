// 繪製點陣圖像

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const uint32_t leftArrow[] = {  // 左箭頭圖案
  0x10030,
  0x7FEFFE7,
  0xFE300100
};

const uint32_t rightArrow[] = {  // 右箭頭圖案
  0x800,
  0xC7FE7FF7,
  0xFE00C008
};

void setup() {
  matrix.begin();
}
  
void loop(){
  matrix.loadFrame(leftArrow);  // 載入並顯示左箭頭
  delay(1000);
  matrix.loadFrame(rightArrow); // 載入並顯示右箭頭
  delay(1000);
}
