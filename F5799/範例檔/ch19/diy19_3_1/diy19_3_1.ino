// 顯示比讚

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  matrix.begin();
  matrix.loadFrame(LEDMATRIX_LIKE);
}

void loop() { }