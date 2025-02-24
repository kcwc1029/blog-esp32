void setup() {
    Serial.begin(115200);  // 設定序列監控的波特率
    Serial.println("ESP32 Serial Monitor Lab 開始...");
    Serial.println("輸入 'STOP' 即可停止輸出！");
}

void loop() {
    static bool running = true;  // 用來記錄是否應該繼續輸出

    if (running) {
        Serial.println("ESP32 Running...");  // 持續輸出訊息
        delay(1000);  // 每秒輸出一次
    }

    if (Serial.available()) {  // 檢查是否有輸入資料
        String input = Serial.readStringUntil('\n');  // 讀取輸入內容
        input.trim();  // 移除前後空白或換行符號

        if (input == "STOP") {  // 若輸入 STOP，則停止輸出
        Serial.println("ESP32 停止輸出，請重新啟動以繼續...");
        running = false;
        }
    }
}