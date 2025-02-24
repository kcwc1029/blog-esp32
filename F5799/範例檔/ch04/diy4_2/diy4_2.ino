// LED 切換開關

const byte LED_PIN = 13;
const byte SW_PIN = 8;    // 開關在腳8
bool lastState = LOW; // 記錄上次的開關狀態，預設為「低電位」
bool toggle = 0;    // 輸出給 LED 的訊號，預設為0，等同LOW。

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
    lastState = b1;
  }

  if (b1 != lastState)
  {
    toggle = 1- toggle;  // 另一種寫法：toggle = !toggle;
    digitalWrite(LED_PIN, toggle);
    lastState = LOW;
  }
}