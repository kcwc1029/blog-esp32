#include <WiFi.h>       // 引入 Wi-Fi 函式庫
#include <WebServer.h>  // 引入 WebServer 函式庫（ESP32 內建 Web 伺服器）

// 設定 SoftAP 模式的 Wi-Fi 名稱與密碼
const char *ssid = "ESP32-AP";       // 設定 AP 熱點名稱
const char *password = "12345678";   // 設定 AP 密碼（至少 8 碼）

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
    digitalWrite(LED, HIGH);  // 讓 LED 亮起
    server.send(200, "text/html; charset=UTF-8", "<p>LED 已開啟</p><a href=\"/off\">關閉 LED</a>");
}

// 關閉 LED 的請求處理
void handleLedOff() {
    digitalWrite(LED, LOW);  // 讓 LED 熄滅
    server.send(200, "text/html; charset=UTF-8", "<p>LED 已關閉</p><a href=\"/on\">開啟 LED</a>");
}

void setup() {
    Serial.begin(115200);  // 設定序列監視器
    pinMode(LED, OUTPUT);  // 設定 LED 腳位為輸出模式

    // 啟動 SoftAP（建立 ESP32 為 Wi-Fi 熱點）
    WiFi.softAP(ssid, password);
    Serial.println("\nWi-Fi 熱點已建立！");
    Serial.print("SSID: ");
    Serial.println(ssid);
    Serial.print("ESP32 AP 模式 IP 地址: ");
    Serial.println(WiFi.softAPIP());  // 顯示 SoftAP 模式下 ESP32 的 IP 地址

    // 註冊處理函式
    server.on("/", handleRoot);          // 根目錄，顯示 LED 控制選單
    server.on("/on", handleLedOn);       // 訪問 /on 讓 LED 亮起
    server.on("/off", handleLedOff);     // 訪問 /off 讓 LED 熄滅
    server.onNotFound(handleNotFound);   // 404 錯誤處理

    server.begin();  // 啟動 Web 伺服器
    Serial.println("HTTP 伺服器已啟動，等待請求...");
}

void loop() {
    server.handleClient();  // 處理 HTTP 請求
}