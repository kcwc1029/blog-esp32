void setup() {
    Serial.begin(115200);  // 啟動序列埠，波特率設為 115200
}

void loop() {
    Serial.println("ESP32 is running...");  // 每秒輸出訊息
    delay(1000);
}