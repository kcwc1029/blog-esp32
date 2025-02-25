#include <WiFi.h>       // 引入 Wi-Fi 函式庫
#include <WebServer.h>  // 引入 WebServer 函式庫（ESP32 內建 Web 伺服器）
#include "config.h"

// const char *ssid = "你的WiFi名稱";      // 無線網路 SSID
// const char *password = "你的WiFi密碼";  // 無線網路密碼

// 設定 LED 腳位
const byte LED = 2;

// 建立 WebServer 物件，監聽 80 號埠（HTTP）
WebServer server(80);

// 處理首頁請求，提供 LED 控制按鈕
void handleRoot() {
    String HTML = "<h1>ESP32 LED 控制</h1>";
    HTML += "<p><a href=\"/on\">開啟 LED</a></p>";
    HTML += "<p><a href=\"/off\">關閉 LED</a></p>";
    server.send(200, "text/html; charset=UTF-8", HTML);
}

// 當找不到頁面時的處理
void handleNotFound() {
    server.send(404, "text/html; charset=UTF-8", "錯誤 404：找不到頁面");
}

// 開啟 LED 的請求處理
void handleLedOn() {
    Serial.println("LED 亮起");
    // digitalWrite(LED, HIGH);  // 讓 LED 亮起
    server.send(200, "text/html; charset=UTF-8", "<p>LED 已開啟</p><a href=\"/off\">關閉 LED</a>");
}

// 關閉 LED 的請求處理
void handleLedOff() {
    Serial.println("LED 熄滅");
    // digitalWrite(LED, LOW);  // 讓 LED 熄滅
    server.send(200, "text/html; charset=UTF-8", "<p>LED 已關閉</p><a href=\"/on\">開啟 LED</a>");
}

void setup() {
    Serial.begin(115200);  // 設定序列監視器
    pinMode(LED, OUTPUT);  // 設定 LED 腳位為輸出模式
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  // 連接 Wi-Fi

    Serial.print("連接 Wi-Fi 中");
    while (WiFi.status() != WL_CONNECTED) {  // 等待 Wi-Fi 連線
        delay(500);
        Serial.print(".");
    }
    delay(3000);
    Serial.println("\nWi-Fi 連線成功！");
    Serial.print("ESP32 IP 地址: ");
    Serial.println(WiFi.localIP());  // 顯示 ESP32 的 IP 地址

    // 註冊處理函式
    server.on("/", handleRoot);          // 根目錄，顯示 LED 控制選單
    server.on("/on", handleLedOn);       // 訪問 /on 讓 LED 亮起
    server.on("/off", handleLedOff);     // 訪問 /off 讓 LED 熄滅
    server.onNotFound(handleNotFound);   // 404 錯誤處理

    server.begin();  // 啟動 Web 伺服器
    Serial.println("HTTP 伺服器已啟動");
}

void loop() {
    server.handleClient();  // 處理 HTTP 請求
}