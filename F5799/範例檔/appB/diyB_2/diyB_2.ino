// 處理 GET 或 POST 請求

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "你的網路名稱";
const char *password = "網路密碼";

ESP8266WebServer server(80);

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
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nIP位址：");
  Serial.println(WiFi.localIP()); // 顯示IP位址

  server.on("/", handleRoot); // 處理首頁連結請求的事件
  server.on("/about", []() {
    server.send(200, "text/html", "hello world!");
  });
  server.on("/sw", []() {
    String state = server.arg("led");
    if (state == "on")
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if (state == "off")
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    server.send(200, "text/html", "LED is <b>" + state + "</b>.");
  });
  server.onNotFound([]() { // 處理「找不到指定路徑」的事件
    server.send(404, "text/plain", "File NOT found!");
  });
  server.begin(); // 啟動網站伺服器
}

void loop(void)
{
  server.handleClient();
}
