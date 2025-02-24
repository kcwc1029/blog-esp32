// 輸出正弦波訊號

void setup() {
  analogWriteResolution(12);  // 設DAC解析度為12位元
}

void loop() {
  static int deg=0;
  analogWrite(A0, int(2048 + 1000*sin(deg * PI/180)));
  deg++;
  if (deg > 360) deg=0;
  delay(20);  // 設定輸出訊號的週期時間：20ms × 360
}
