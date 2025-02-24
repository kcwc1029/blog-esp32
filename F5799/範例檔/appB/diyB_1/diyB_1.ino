//  使用 ESP8266WebServer程式庫建立 HTTP 伺服器

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "你的網路名稱";
const char *password = "網路密碼";
ESP8266WebServer server(80); // 建立網站伺服器物件

void handleRoot()
{
  String HTML = "<!DOCTYPE html>\
  <html><head><meta charset='utf-8'></head>\
  <body>漫漫長路，總要從第一步開始。\
  </body></html>";
  server.send(200, "text/html", HTML);
}

void setup(void)
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);        // 設定成STA模式
  WiFi.begin(ssid, password); // 連線到Wi-Fi網路分享器

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nIP address: ");
  Serial.println(WiFi.localIP()); // 顯示IP位址
  server.on("/", handleRoot);     // 處理首頁的路由
  server.on("/about", []() {      // 處理”/about”路徑的路由
    server.send(200, "text/html", "hello world!");
  });
  server.onNotFound([]() { // 處理「找不到指定資源」的路由
    server.send(404, "text/plain", "File NOT found!");
  });

  server.begin(); // 啟動網站伺服器
}

void loop(void)
{
  server.handleClient(); // 處理用戶端連線
}
