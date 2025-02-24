// 啟用內建的上拉電阻，
const byte LED = 13;
const byte SW = 8;

void setup()
{
   pinMode(LED, OUTPUT);
   pinMode(SW, INPUT_PULLUP); // 啟用開關接腳內部的上拉電阻
}
void loop()
{
   bool val = digitalRead(SW);
   digitalWrite(LED, val);
}
