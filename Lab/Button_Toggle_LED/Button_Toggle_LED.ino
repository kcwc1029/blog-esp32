#define LED_PIN 5       // LED 連接到 GPIO5
#define BUTTON_PIN 15   // 按鈕 連接到 GPIO15（內建 PULLUP）

bool ledState = LOW;   // LED 初始狀態

void setup() {
  pinMode(LED_PIN, OUTPUT);           // 設定 LED 為輸出
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 使用內建 PULLUP，按下時變 LOW
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {  // 按鈕按下
    delay(50);  // 消抖
    if (digitalRead(BUTTON_PIN) == LOW) {  // 確保按鈕仍然按下
      ledState = !ledState;   // 切換 LED 狀態
      digitalWrite(LED_PIN, ledState);  // 更新 LED
      while (digitalRead(BUTTON_PIN) == LOW);  // 等待按鈕放開
      delay(50);  // 再次消抖
    }
  }
}
