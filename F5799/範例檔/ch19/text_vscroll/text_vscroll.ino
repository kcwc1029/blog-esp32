// 捲動中文訊息

#include "Arduino_LED_Matrix.h"
#include "fonts.h"

ArduinoLEDMatrix matrix;

byte frame[9][12] = { 0 };
byte fontSize = sizeof(fonts) / sizeof(fonts[0]);

void scroll_col() {                           // 往上捲動LED矩陣
  for (byte col = 0; col < 8; col++)          // 每一行…
    memcpy(frame[col], frame[col+1], sizeof(frame[col]));
    // for (byte row = 0; row < 12; row++)       // 的每一列…
    //   frame[col][row] = frame[col + 1][row];  // 下一行的每一列複製給前一行
}

void setup() {
  matrix.begin();
  matrix.renderBitmap(frame, 8, 12);
}

void loop() {
  // delay(500);
  for (byte i = 0; i < fontSize; i++) {
    byte colSize = fonts[i][0];

    for (byte col = 1; col <= colSize; col++) {
      for (byte row = 0; row < 12; row++)
        frame[8][row] = (fonts[i][col] >> row) & 1;
      scroll_col();
      matrix.renderBitmap(frame, 8, 12);
      delay(50);
    }

    // 空行
    // for (byte row = 0; row < 12; row++)
    //   frame[8][row] = 0;
    memset(frame[8], 0, sizeof(frame[8]));
    scroll_col();

    matrix.renderBitmap(frame, 8, 12);
    delay(50);
  }
}