// 動手做16-1-2：UNO R4板的Serail1物件

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // 將LED接腳設定為「輸出」
  Serial1.begin(9600);              // 初始化UART序列埠（Serial1）
  Serial1.println("BT is ready!");  // 連線成功後，發佈「準備好了」訊息。
}
void loop() {
  if (Serial1.available()) {    // 如果有資料進來…
    // delay(2);    // 選擇性地暫停2毫秒，讓微控器接收資料。
    char val = Serial1.read();  // 接收UART傳入的字元資料
    switch (val) {
      case '0':                          // 若接收到'0'
        digitalWrite(LED_BUILTIN, LOW);  // 關閉LED
        break;
      case '1':                           // 若接收到'1'
        digitalWrite(LED_BUILTIN, HIGH);  // 點亮LED
        break;
    }
  }
}