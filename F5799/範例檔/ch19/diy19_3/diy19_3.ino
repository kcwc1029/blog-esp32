#include <WiFiS3.h>		// 處理Wi-Fi網路連線程式庫
#include <Arduino_LED_Matrix.h>  // 操控LED點陣的程式庫
#include "wifi_anima.h"   // 自訂的Wi-Fi動畫圖像資料

#define SSID "你的WiFi名稱"
#define PASSWORD "WiFi密碼"

ArduinoLEDMatrix matrix;  // 宣告LED點陣物件

const uint32_t cat[] = {    // 單一圖像資料
  0x2045fa80,
  0x1b0d8058,
0x418217fe
};
 
void setup() {
  Serial.begin(9600);
  matrix.begin();  // 啟用LED點陣
  matrix.loadSequence(wifi_anima); // 載入動畫圖像資料
  matrix.play(true);    // 反覆播放動畫

  while (WiFi.status() != WL_CONNECTED) {  // 若尚未連線Wi-Fi…
    WiFi.begin(SSID, PASSWORD);     // Wi-Fi連線
    delay(1000);
  }

  matrix.loadFrame(cat);   // 若連線成功…載入單一圖像cat。
}

void loop() { }
