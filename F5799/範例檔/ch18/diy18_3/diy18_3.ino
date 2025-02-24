// 動手做18-3：建立微型網站伺服器

#include <WiFiS3.h>  // 引用此程式庫

const char* ssid = " Wi-Fi名稱";  // 請輸入你的Wi-Fi網路名稱和密碼-
const char* password = " Wi-Fi密碼";

WiFiServer server(80);  // 建立網站伺服器物件，命名為”server”，連接埠80。

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);  // 連線到Wi-Fi熱點
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.print("\n已連上：");
  Serial.println(WiFi.SSID());

  long rssi = WiFi.RSSI();
  Serial.print("訊號強度（RSSI）：");
  Serial.print(rssi);
  Serial.println(" dBm");

  IPAddress ip = WiFi.localIP();
  Serial.print("Arduino的IP位址：");
  Serial.println(ip);

  server.begin();  // 啟動網站伺服器
}


void loop() {
  WiFiClient client = server.available();

  if (client) {
    while (client.connected()) {
      String req;
      if (client.available()) {
        req = client.readStringUntil('\n');
        if (req.length() == 1) {
          String resp =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "\n"
            "<!DOCTYPE html><html><head>\n"
            "<meta charset=\"utf-8\">"
            "<title>超圖解</title></head>\n"
            "<body>漫漫長路，總要從第一步開始。</body></html>";
            
          client.println(resp);
          break;
        }
      }
    }
    client.stop();
  }
}
