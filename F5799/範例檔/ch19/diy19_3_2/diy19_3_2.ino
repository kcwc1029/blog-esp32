// 搜尋Wi-Fi訊號

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;  

void setup() {
  matrix.begin();
  matrix.loadSequence(LEDMATRIX_ANIMATION_WIFI_SEARCH);
  matrix.play(true);
}

void loop() { }