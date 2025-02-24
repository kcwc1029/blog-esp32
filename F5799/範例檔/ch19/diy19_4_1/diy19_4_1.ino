// 動手做19-4：在LED點陣捲動顯示本機IP位址

#include <ArduinoGraphics.h>     // 先引用「Arduino圖像」程式庫
#include <Arduino_LED_Matrix.h>  // 再引用LED點陣程式庫
#include <WiFiS3.h>
#include "wifi_anima.h"  
#define SSID "Wi-Fi熱點名稱"
#define PASSWORD "Wi-Fi密碼"

ArduinoLEDMatrix matrix;  // 控制LED點陣的物件
IPAddress myIP;        // 儲存IP位址的物件。

void drawIP() {          // 呈現捲動的IP位址
  matrix.beginDraw();
  matrix.textScrollSpeed(50);   // 捲動速度50毫秒
  matrix.textFont(Font_5x7);		// 指定字體
  matrix.beginText(8, 1, 0xffffff);  // 在 (8, 1) 顯示文字，「點亮」LED。
  matrix.print(myIP);   // 顯示IP位址
  matrix.endText(SCROLL_LEFT);  // 向左捲動
  matrix.endDraw();
}

void setup() {
  matrix.begin();
  matrix.loadSequence(wifi_anima);
  matrix.play(true);   // 循環播放Wi-Fi連線動畫

  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(SSID, PASSWORD);
    delay(1000);
  }

  myIP = WiFi.localIP();  // 取得IP位址
}
void loop() {
  drawIP();   // 捲動顯示IP位址
}