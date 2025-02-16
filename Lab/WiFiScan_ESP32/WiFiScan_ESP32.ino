#include "WiFi.h"  // 引入 Wi-Fi 函式庫

bool scanning = true;  // 掃描狀態變數，控制 Wi-Fi 掃描是否繼續執行

// 初始化系統
void setup() {
    Serial.begin(9600);  // 設定 Serial 監視器波特率為 9600
    Serial.println("\n[系統啟動] ESP32 Wi-Fi 掃描器");

    initWiFi();  // 初始化 Wi-Fi 設定
    delay(100);  // 確保 Wi-Fi 初始化完成

    Serial.println("[初始化完成] 準備開始 Wi-Fi 掃描\n");
    Serial.println("📌 請在序列監視器輸入 'q' 並按 Enter 來停止掃描");
}

// 主迴圈：重複掃描 Wi-Fi，直到使用者按 'q' 停止
void loop() {
    if (!scanning) {  // 如果使用者輸入 'q'，則停止掃描
        Serial.println("[系統已停止 Wi-Fi 掃描]");
        while (true);  // 進入無限迴圈，停止程式運行
    }

    Serial.println("[掃描開始] 正在搜尋 Wi-Fi 網路...");

    int networkCount = WiFi.scanNetworks();  // 開始掃描 Wi-Fi，回傳找到的熱點數量

    Serial.println("[掃描完成]");
    if (networkCount == 0) {
        Serial.println("⚠ 沒有發現任何 Wi-Fi 熱點\n");
    } else {
        Serial.printf("✅ 發現 %d 個 Wi-Fi 熱點：\n", networkCount);
        for (int i = 0; i < networkCount; i++) {
            Serial.printf(
                "%d. SSID: %s | 訊號強度: %d dBm | 安全性: %s\n",
                i + 1,
                WiFi.SSID(i).c_str(),  // 取得 Wi-Fi SSID
                WiFi.RSSI(i),         // 取得 Wi-Fi 訊號強度 (RSSI)
                (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "開放" : "加密"
            );
            delay(10);  // 避免輸出過快，導致資料錯亂
        }
        Serial.println("");  // 空行區隔
    }

    Serial.println("[等待 5 秒，然後重新掃描...]\n");
    
    // 等待期間檢查使用者是否輸入 'q'
    for (int i = 0; i < 50; i++) {  // 50 x 100ms = 5000ms (5 秒)
        if (Serial.available()) {  // 檢查是否有輸入
            char userInput = Serial.read();  // 讀取使用者輸入
            if (userInput == 'q' || userInput == 'Q') {  // 若輸入 'q' 則停止掃描
                scanning = false;
                break;  // 跳出等待
            }
        }
        delay(100);  // 每 100ms 檢查一次
    }
}

// Wi-Fi 初始化函式
void initWiFi() {
    WiFi.mode(WIFI_STA);  // 設定為「工作站模式」，避免啟動 AP
    WiFi.disconnect();     // 斷開當前 Wi-Fi 連線，確保乾淨的掃描
    Serial.println("[Wi-Fi 初始化完成]");
}
