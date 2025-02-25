#include <WiFi.h>
#include "config.h"


// const char *ssid = "";      // 無線網路基地台的 SSID
// const char *password = "";  // 無線網路基地台的密碼

void setup() {
    Serial.begin(115200);  // 初始化序列埠通訊
    connectWiFi();  // 連線 Wi-Fi
}

// 主迴圈：監聽使用者輸入 'q'，決定是否斷開 Wi-Fi
void loop() {
    checkUserInput();  // 監聽序列埠輸入
}

// Wi-Fi 連線函式
void connectWiFi() {
    Serial.print("正在連線到 Wi-Fi: ");
    Serial.println(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    delay(3000);
    Serial.println("\n✅ 已成功連上 Wi-Fi");
    Serial.print("📡 我的 IP 位址：");
    Serial.println(WiFi.localIP());

    Serial.print("🌐 子網路遮罩：");
    Serial.println(WiFi.subnetMask());

    Serial.print("🚪 閘道器位址：");
    Serial.println(WiFi.gatewayIP());

    Serial.print("🔗 DNS 位址：");
    Serial.println(WiFi.dnsIP());

    Serial.println("📌 請在序列監視器輸入 'q' 來斷開 Wi-Fi 連線");
}

// 檢查使用者輸入函式
void checkUserInput() {
    if (Serial.available()) {  // 檢查是否有輸入
        char userInput = Serial.read();  // 讀取使用者輸入
        if (userInput == 'q' || userInput == 'Q') {  // 若輸入 'q' 則斷開 Wi-Fi
            Serial.println("\n🚫 [指令] 斷開 Wi-Fi 連線中...");
            WiFi.disconnect();  // 斷開 Wi-Fi 連線
        }
    }
}

