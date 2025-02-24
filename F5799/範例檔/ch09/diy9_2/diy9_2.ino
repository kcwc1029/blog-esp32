//  掃描 I2C 匯流排連接的週邊位址

#include <Wire.h>

void setup() {
  byte total, code;

  Wire.begin();   // 初始化I2C通訊介面
  Wire.setClock(100000UL);
  Serial.begin(9600);
  Serial.println("掃描I2C…");
  
// 開始掃描（傳送位址）
  for (byte addr = 1; addr < 127; addr++ ) {
    Wire.beginTransmission(addr);
    code = Wire.endTransmission();

    if (code == 0) {  // 有裝置回應，顯示位址。
      Serial.print("發現裝置位址: 0x");
      Serial.println(addr, HEX); 
      total ++;   // 總數加1
    } else if (code==4) {
      Serial.println("發生不知名錯誤: 0x");
      Serial.println(addr, HEX);
    }
  }

  if (total == 0)
    Serial.println("沒發現I2C裝置");
}

void loop() { }
