// 自訂字元動畫

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte sp[6][8] = {
  {B00100, B01110, B11111, B10101, B11111, B01110, B01010, B10001},
  {B00100, B01110, B11111, B11010, B11111, B00100, B01010, B01010},
  {B00100, B01110, B11111, B11110, B11111, B01110, B00100, B00100},
  {B00100, B01110, B11111, B11111, B11111, B00100, B01010, B01010},
  {B00100, B01110, B11111, B01111, B11111, B01110, B00100, B00100},
  {B00100, B01110, B11111, B01101, B11111, B00100, B01010, B01010}
};

byte index = 0;  // 字元索引
void setup(){
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.createChar(0, sp[0]);
  lcd.createChar(1, sp[1]);
  lcd.createChar(2, sp[2]);
  lcd.createChar(3, sp[3]);
  lcd.createChar(4, sp[4]);
  lcd.createChar(5, sp[5]);
  lcd.home();
  lcd.print("Invader");
}

void loop(){
  lcd.setCursor(8, 0);  // 游標固定在第0列中間
  lcd.write(index);
  if ( ++index > 5) {   // 將index值限制在0~5
    index = 0; 
  }
  delay(300);       // 等待0.3秒再顯示下一個字元
}