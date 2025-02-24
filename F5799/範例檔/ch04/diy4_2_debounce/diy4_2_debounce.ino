// 用程式解決開關訊號的彈跳問題

const byte LED_PIN = 13;
const byte SW_PIN = 8;    // 開關在腳8
bool lastState = LOW; // 記錄上次的開關狀態，預設為「低電位」
bool toggle = LOW;    // 輸出給 LED 的訊號，預設為「低電位」

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(SW_PIN, INPUT);
}

void loop()
{
  bool b1 = digitalRead(SW_PIN);

  if (b1)
  {
    delay(20);                 // 等待20毫秒
    bool b2 = digitalRead(SW_PIN); // 再次讀取開關值

    if (b1 == b2)
    {                 // 確認兩次開關值是否一致
      lastState = b1; // 儲存開關的狀態
    }
  }

  if (b1 != lastState)
  {
    toggle = !toggle;
    digitalWrite(LED_PIN, toggle);
    lastState = LOW;
  }
}
