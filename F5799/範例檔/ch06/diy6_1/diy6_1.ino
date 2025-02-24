// 動手做6-1：連接 LED 七段顯示器與Arduino板

byte index = 0;
const byte LEDs[10] = {
    B1111110,
    B0110000,
    B1101101,
    B1111001,
    B0110011,
    B1011011,
    B1011111,
    B1110000,
    B1111111,
    B1111011};
void setup()
{
  DDRD = B11111111; // 將 0~7 腳全設定成「輸出」
}
void loop()
{
  PORTD = LEDs[index];

  index++;
  if (index == 10)
  {
    index = 0;
  }
  delay(1000);
}
