// 動手做8-5：使用UNO R4內建的運算放大器製作麥克風放大器

#include <OPAMP.h>

const byte micPin = A4;   // 麥克風訊號輸入腳
bool toggle = false;     // LED的狀態，預設為不亮。

unsigned long nowClap = 0;  // 當前的拍手時間
unsigned long lastClap = 0; // 上次的拍手時間
unsigned int claps = 0;     // 拍手次數
unsigned long timeDiff = 0; // 拍手時間差

void setup() {  
  pinMode(LED_BUILTIN, OUTPUT);  // LED接腳設定為「輸出」
  Serial.begin(9600);
  while (!Serial) ;

  if (!OPAMP.begin(OPAMP_SPEED_LOWSPEED)) {  //以低速啟用運算放大器
    Serial.println("無法啟用運算放大器！");
    while (true) delay(1000);   // 程式將停在這裡
  }

  bool const running = OPAMP.isRunning(0);  // 查看通道0的運算放大器是否在運作狀態
  if (running) {
    Serial.println("通道0的運算放大器開工了！");
  } else {
    Serial.println("通道0的運算放大器沒有運作…");
  }
}  

void loop() {
  int micVal = analogRead(micPin);  // 麥克風音量值

  if (micVal > 500) {  // 如果音量大於500
    nowClap = millis(); // 儲存當前的毫秒數
    
    claps ++;         // 拍手次數加1
    // 顯示拍手次數
    Serial.println(claps);
    
    if (claps == 2) {  // 若拍了兩次...
      timeDiff = nowClap - lastClap;  // 求取時間差
      // 如果兩次拍手的間隔時間在0.3~1.5秒之間...
      if (timeDiff > 300 && timeDiff< 1500) {
        toggle = !toggle;  // 將LED的狀態值反相
        claps = 0;  // 重設拍手次數
      } else {
        claps = 1;  // 若第二次拍手間隔太短或太長，就算拍一次。
      }
    }
    // 儲存目前時間給下一次比較「時間差」
    lastClap = nowClap;
  }
  
  digitalWrite(LED_BUILTIN, toggle);
}

