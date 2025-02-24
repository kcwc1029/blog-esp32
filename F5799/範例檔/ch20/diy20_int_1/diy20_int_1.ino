// 輪詢VS中斷 1

const byte SW_PIN = 2;		// 開關接在數位2腳
bool state;			// 暫存按鈕狀態的變數

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);	// 內建LED腳設定為「輸出」
  pinMode(SW_PIN, INPUT_PULLUP);  // 啟用微控器內部的上拉電阻
}

void loop() {
  state = digitalRead(SW_PIN);		// 讀取第2腳的值
  if (state == LOW) {	// 如果第2腳為「低電位」，則閃爍LED兩次。
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150);
    digitalWrite(LED_BUILTIN, LOW);
    delay(150);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
