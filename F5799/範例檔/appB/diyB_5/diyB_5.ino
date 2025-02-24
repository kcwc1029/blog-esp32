#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>  // 非同步網站伺服器程式庫

const char* ssid = "你的WiFi網路名稱";
const char* pwd = "WiFi密碼";

AsyncWebServer server(80);  // 偵聽80埠的非同步網站伺服器物件

void setup() {
  Serial.begin(115200);
  if (!SPIFFS.begin()) {
    // 若無法初始化SPIFFS…
    Serial.println("無法掛載SPIFFS檔案系統…");
    return;  // 退出setup，不執行其餘程式。
  }

  server.serveStatic("/", SPIFFS, "/www/").setDefaultFile("index.html");
  server.serveStatic("/img", SPIFFS, "/www/img/");
  server.serveStatic("/favicon.ico", SPIFFS, "/www/favicon.ico");

  server.begin();  // 啟動伺服器
  Serial.println("HTTP server started");
}

void loop() { }
