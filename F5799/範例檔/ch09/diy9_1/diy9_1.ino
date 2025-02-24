// 動手做9-1：在 LCD 顯示器上顯示一段文字

#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 12, 6, 5, 4, 3);

void setup()
{
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}
void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
