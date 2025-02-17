uint64_t chipid;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // 取得 ESP32 的 MAC 地址（作為晶片 ID）
  chipid = ESP.getEfuseMac();  // ESP32 的 MAC 地址（6 bytes）

  // 輸出晶片 ID
  Serial.printf("ESP32 Chip ID = %04X", (uint16_t)(chipid >> 32));  // 高 2 bytes
  Serial.printf("%08X\n", (uint32_t)chipid);                        // 低 4 bytes

  delay(3000);  // 每 3 秒顯示一次晶片 ID

  // 檢查使用者輸入，若輸入 'q' 則停止程式
  if (Serial.available()) {          // 檢查是否有輸入
    char userInput = Serial.read();  // 讀取輸入字元
    if (userInput == 'q' || userInput == 'Q') {
      Serial.println("[系統停止] 停止顯示 ESP32 Chip ID");
      while (true);  // 進入無限迴圈，停止程式
    }
  }
}
