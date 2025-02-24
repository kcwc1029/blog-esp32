// 類比參考腳位

int val = 0;

void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);  // 採用AREF作為類比參考電壓值
}

void loop() {
  val = analogRead(A0);  // 讀取A0腳位值（最高輸入3.3V）
  Serial.println(val);   // 在序列埠監控窗輸出類比值（0~1023）
  delay(500);
}