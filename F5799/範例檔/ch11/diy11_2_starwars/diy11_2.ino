// 動手做11-2：電音蝌蚪

#include <analogWave.h>  // 引用此程式庫
#define BTN_PIN 2       // 定義開關接腳

analogWave wave(DAC);  // 建立analogWave物件，使用DAC腳

int freq = 10;  // 定義儲存頻率值（Hz單位）的變數

void setup() {
  Serial.begin(9600);
  pinMode(BTN_PIN, INPUT);
  wave.sine(freq);  // 以初設頻率產生正弦波
  wave.stop();      // 停止輸出訊號
}

void loop() {
  // 讀取A5腳的類比值並將它對應成200~2.5kHz頻率值
  freq = map(analogRead(A5), 0, 1023, 200, 2500);
  Serial.println(String(freq) + " Hz");  // 顯示目前的頻率值

  bool sw = digitalRead(BTN_PIN);    // 讀取腳2的開關狀態
  if (sw == 0) {       // 若開關被按下…
    wave.freq(freq);  // 設置DAC輸出頻率
  } else {
    wave.stop();     // 停止輸出訊號
  }
}
