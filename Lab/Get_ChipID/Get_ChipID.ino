uint64_t chipid;
void setup() {
    Serial.begin(115200);
}

void loop() {
    // 取得 ESP32 的 MAC 地址（作為晶片 ID）
    chipid = ESP.getEfuseMac();  // ESP32 的 MAC 地址（6 bytes）
    Serial.printf("ESP32 Chip ID = %04X", (uint16_t)(chipid >> 32));  // 高 2 bytes
    Serial.printf("%08X\n", (uint32_t)chipid);                        // 低 4 bytes

    delay(3000);  
    
    // 檢查使用者輸入，若輸入 'q' 則停止程式
    if (Serial.available()) {          
        char userInput = Serial.read();  
        if (userInput == 'q' || userInput == 'Q') {
        Serial.println("[系統停止] 停止顯示 ESP32 Chip ID");
        while (true);  // 進入無限迴圈，停止程式
        }
    }
}