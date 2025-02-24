// 動手做8-5：使用UNO R4內建的運算放大器製作麥克風放大器

#include <OPAMP.h>  // 要引用這個程式庫

void setup () {
  Serial.begin(9600);
  while (!Serial) ;  // 等待序列埠初始化成功

  if (!OPAMP.begin(OPAMP_SPEED_LOWSPEED)) {  //以低速啟用運算放大器
    Serial.println("無法啟用運算放大器！");
    while (true) delay(1000);   // 若無法啟用OPA，程式將停在這裡。
  }

  bool const running = OPAMP.isRunning(0);  // 查看通道0的運算放大器是否在運作狀態
  if (running) {
    Serial.println("通道0的運算放大器開工了！");
  } else {
    Serial.println("通道0的運算放大器沒有運作…");
  }
}

void loop() {
  int val = analogRead(A4);
  Serial.println(val);
  delay(10);
}
