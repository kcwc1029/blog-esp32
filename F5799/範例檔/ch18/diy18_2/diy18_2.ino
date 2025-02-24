// 動手做18-2：連線到Wi-Fi網路並顯示IP位址和電波訊號強度
#include <WiFiS3.h>

const char* ssid="Wi-Fi名稱";
const char* pwd ="Wi-Fi密碼";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.print("IP位址：");
  Serial.println(WiFi.localIP());
  Serial.print("訊號強度（RSSI）：");
  Serial.println(WiFi.RSSI());
}

void loop() { }