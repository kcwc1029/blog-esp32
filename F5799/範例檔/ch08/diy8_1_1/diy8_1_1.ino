// 調整Arduino UNO R4開發板的類比輸入解析度

const byte potPin = A0;

void setup() {
  Serial.begin(9600);  // 以9600bps速率初始化序列埠
  analogReadResolution(14);  // 類比數位轉換器解析度設為14位元
}

void loop() {
  int val = analogRead(potPin);  // 讀取並暫存類比輸入值
  Serial.println(val);
  delay(500);
}