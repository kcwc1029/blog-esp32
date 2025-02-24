// 使用 ESP8266 的 WiFi 程式庫 連接無線網路

#include <ESP8266WiFi.h>

const char *ssid = "你的無線網路名稱";
const char *password = "你的網路密碼";

void setup(void)
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);        // 設定成STA模式
  WiFi.begin(ssid, password); // 連線到Wi-Fi網路分享器

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.print("\nIP位址：");
  Serial.println(WiFi.localIP()); // 顯示IP位址
  Serial.print("WiFi RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop(void)
{
}
