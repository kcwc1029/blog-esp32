// 顯示MAC位址與掃描Wi-Fi網路熱點

#include <WiFiS3.h>

void printMacAddress(byte mac[]) {
  for (int i = 0; i < 6; i++) { // 分別取出6組數字
    if (i > 0) {
      Serial.print(":");  // 第1組數字之後都要顯示“:”號
    }
    if (mac[i] < 16) {  // 如果數值小於16，則補上0。
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);  // 以16進位值呈現
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("連不上Wi-Fi網路模組！");
    while (true)
      delay(1000);
  }

  byte mac[6];  // 儲存MAC位址的陣列
  WiFi.macAddress(mac);
  Serial.println();
  Serial.print("Arduino開發板的MAC位址：");
  printMacAddress(mac);
}

void loop() { }
