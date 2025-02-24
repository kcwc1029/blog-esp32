// 輪詢VS中斷 1

const byte SW_PIN = 2;   // 開關（觸發中斷）腳
const byte LED_PIN = 13;
volatile boolean state = LOW;

void swISR() {
  state = !state;
  digitalWrite(LED_PIN, state);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SW_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(SW_PIN), 
                  swISR, CHANGE); // 啟用中斷處理功能
}

void loop() { }