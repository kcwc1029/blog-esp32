// 動手做20-1：模擬USB鍵盤和滑鼠

#include <Keyboard.h>  // 鍵盤程式庫
#include <Mouse.h>    // 滑鼠程式庫
#define SW_PIN 2   // 開關在腳2

void setup() {
  Keyboard.begin();  // 初始化鍵盤
  Mouse.begin();    // 初始化滑鼠
  pinMode(SW_PIN, INPUT_PULLUP);  // 開關腳啟用「上拉電阻」
}

void loop() {
  bool keyPressed = digitalRead(SW_PIN);

  if (keyPressed == LOW) {  // 若按下按鍵…
    Keyboard.press(KEY_LEFT_ALT); // 按著左ALT鍵
    Keyboard.press(KEY_PRINT_SCREEN);   // 按著PrtScr鍵
    delay(100);
    Keyboard.releaseAll(); // 放開全部按鍵
    delay(100);
    Mouse.move(-30,-30);  // 游標往左上移動
    delay(500);
    Mouse.move(30,30);  // 游標往右下移動
    delay(500); 
  }
}
