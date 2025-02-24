// 動手做18-4：網路控制開關

#include <WiFiS3.h>
#define LED_PIN 13

const char *ssid = "Wi-Fi名稱";
const char *password = "Wi-Fi密碼";

WiFiServer server(80);  // 建立網站伺服器物件

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); 

  WiFi.begin(ssid, password);  // 連線到Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.print("IP位址：");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {  // 若有用戶端連線
    String req = "";
    while (client.connected()) {
      if (client.available()) {
        req = client.readStringUntil('\n');  // 讀取第一行
        break;
      }
    }

    if (req.indexOf("GET /led/on") > -1) {   // 比對文字
      digitalWrite(LED_PIN, HIGH);
    } else if (req.indexOf("GET /led/off") > -1) {
      digitalWrite(LED_PIN, LOW);
    }

    String resp = "HTTP/1.1 200 OK\r\n"
                  "Content-Type: text/html\r\n\r\n"
                  "<!DOCTYPE HTML><html><head><meta charset='utf-8'>"
                  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                  "<title>網路開關</title></head><body>";

    bool ledState = digitalRead(LED_PIN);   // 讀取LED接腳的狀態
    if (ledState) {  // 若是高電位，代表LED目前是亮著的。
    resp += "<a href='/led/off'>關燈</a>";  // 在內文插入「關燈」的超連結
    } else {
      resp += "<a href='/led/on'>開燈</a>";
    }

    resp += "</body></html>";
    client.println(resp);  // 送出回應和HTML碼
    delay(10);
    client.stop();
  }
}
