// UNO R4 Qwiic介面連接I2C裝置

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27); // 宣告lcd物件

void setup() {
  Wire1.begin();           // 初始化Wire1物件（Qwiic介面）
  Wire1.setClock(100000);  // 選擇性地設定I2C時脈100kHz
  lcd.begin(16, 2, Wire1);  // 初始化lcd（行, 列, Wire1物件）
  lcd.setBacklight(255);    // 設定LCD背光亮度
  lcd.print("hello, world!");  // 顯示文字“hello, world!”
}

void loop() { }
