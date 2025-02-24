#include <Bounce2.h>

#define LED_PIN 5       // LED 連接到 GPIO5
#define BUTTON_PIN 15   // 按鈕 連接到 GPIO15（內建 PULLUP）

Bounce debouncer = Bounce(); // 建立 Bounce2 物件
bool ledState = LOW;         // LED 初始狀態

void setup() {
  pinMode(LED_PIN, OUTPUT);             // 設定 LED 為輸出
  pinMode(BUTTON_PIN, INPUT_PULLUP);    // 使用內建 PULLUP，按下時變 LOW

  debouncer.attach(BUTTON_PIN);         // 設定消抖按鈕
  debouncer.interval(20);               // 設定 20ms 消抖時間
}

void loop() {
  debouncer.update();  // 更新按鈕狀態

  if (debouncer.fell()) {  // 檢測到按鈕「剛剛被按下」
    ledState = !ledState;  // 切換 LED 狀態
    digitalWrite(LED_PIN, ledState);
  }
}
