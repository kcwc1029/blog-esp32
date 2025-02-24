// 動手做10-2：隨機數字與燭光效果

byte LED_PIN = 11; // 類比輸出腳位

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  randomSeed(analogRead(A5));
}
void loop()
{
  analogWrite(LED_PIN, random(111) + 120);
  delay(random(200));
}
