// 偵測人體移動

#define PIR_PIN D1 // 紅外線感測器訊號腳位

void setup()
{
  pinMode(PIR_PIN, INPUT);      // 感測器訊號腳位設定成「輸入」
  pinMode(LED_BUILTIN, OUTPUT); // LED腳位設定成「輸出」
}

void loop()
{
  bool val = digitalRead(PIR_PIN); // 讀取感測器值，類型為布林（0或1）。

  digitalWrite(LED_BUILTIN, !val); // 取感測器的相反值點亮或關閉LED
}
