// I2C序列模組LCD

#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);

void setup() {
  lcd.begin(16, 2);    // 初始化LCD（行數, 列數）
  lcd.setBacklight(255);  // 設定背光亮度（0~255）
  lcd.clear();
  lcd.print("Stay hungry,");
  lcd.setCursor(0, 1);  // 游標移到0行、1列。
  lcd.print("stay foolish.");
}

void loop() {}