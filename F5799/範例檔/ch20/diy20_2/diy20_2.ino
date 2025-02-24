// 動手做20-2：使用觸控開關模組製作LED開關

#define SW_PIN 12  // 開關接腳

bool ledState = false;  // 儲存LED狀態
bool lastSWState = LOW; // 儲存開關的上一次狀態

void setup() {
  pinMode(SW_PIN, INPUT); // 開關腳設為「輸入」模式
  pinMode(LED_BUILTIN, OUTPUT);        // LED腳設為「輸出」模式
  digitalWrite(LED_BUILTIN, ledState); 
}

void loop() {
  bool swState = digitalRead(SW_PIN); // 讀取開關狀態

  // 若開關被碰觸，且上一次狀態是「未被碰觸」…
  if (swState == HIGH && lastSWState == LOW) {
    ledState = !ledState;            // 切換LED狀態
    digitalWrite(LED_BUILTIN, ledState);
  }

  lastSWState = swState; // 更新開關的上一次狀態
}
