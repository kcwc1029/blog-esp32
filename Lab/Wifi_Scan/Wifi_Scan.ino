#include "WiFi.h"

bool scanning = true;  // 掃描狀態變數，控制 Wi-Fi 掃描是否繼續執行

void setup() {
    Serial.begin(115200);
    Serial.println("\n[系統啟動] ESP32 Wi-Fi 掃描器");
    initWiFi();  // 初始化 Wi-Fi 設定
    delay(100);
    Serial.println("[初始化完成] 準備開始 Wi-Fi 掃描\n");
    Serial.println("📌 請在序列監視器輸入 'q' 並按 Enter 來停止掃描");
}


void loop() {
    if (!scanning) { 
        Serial.println("[系統已停止 Wi-Fi 掃描]");
        while (true);  // 進入無限迴圈，停止程式運行
    }

    Serial.println("[掃描開始] 正在搜尋 Wi-Fi 網路...");
    int networkCount = WiFi.scanNetworks();  

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
    checkUserInput(5000);
}

// Wi-Fi 初始化函式
void initWiFi() {
    WiFi.mode(WIFI_STA);  // 設定為「工作站模式」，避免啟動 AP
    WiFi.disconnect();    // 斷開當前 Wi-Fi 連線，確保乾淨的掃描
    Serial.println("[Wi-Fi 初始化完成]");
}

// 檢查使用者輸入函式
void checkUserInput(int waitTimeMs) {
    int iterations = waitTimeMs / 100;  
    for (int i = 0; i < iterations; i++) {
        if (Serial.available()) {  
            char userInput = Serial.read(); 
            if (userInput == 'q' || userInput == 'Q') { 
                scanning = false;
                Serial.println("[收到指令] 停止 Wi-Fi 掃描");
                break;  // 跳出等待迴圈
            }
        }
        delay(100);  
    }
}
