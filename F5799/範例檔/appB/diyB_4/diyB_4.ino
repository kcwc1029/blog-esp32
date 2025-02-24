//  從 D1 板（ESP8266） 連結網站伺服器

#include <ESP8266WiFi.h>       // 引用WiFi連線程式庫
#include <ESP8266HTTPClient.h>  // 引用HTTP前端程式庫

const char* ssid = "WiFi網路名稱";
const char* pwd = "WiFi網路密碼";


void getURL(const char* url) {  // 接收網址字串
  if (WiFi.status() == WL_CONNECTED) {  // 若WiFI處於連線狀態…
    WiFiClientSecure client;  // 宣告加密連線的前端物件
    client.setInsecure();     // 以「不安全」模式連線
    HTTPClient https;       // 宣告HTTPS連線物件

    if (https.begin(client, url)) {
      int httpCode = https.GET();  // 取得HTTP回應碼
      Serial.println(String("HTTP回應碼：") + String(httpCode));
      if (httpCode > 0) {  // 若回應碼不是-1，代表伺服器有回應。
        Serial.println(https.getString());  // 顯示伺服器的回應內容
      }
      https.end();  // 結束HTTPS連線
    } else {
      Serial.println("HTTPS連線失敗");
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.print("\nIP位址：");
  Serial.println(WiFi.localIP());

  getURL("https://swf.com.tw/openData/test.html");  // 連線到指定網址
}

void loop() {
}