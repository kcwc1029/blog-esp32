// 在 LCD 上顯示自訂字元符號

#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);

byte sp0[8] = {0x04, 0x0E, 0x1F, 0x15, 
               0x1F, 0x0E, 0x0A, 0x11};

void setup(){
  lcd.begin(16, 2);
  lcd.setBacklight(255);

  lcd.createChar(0, sp0); 
  lcd.home();
  lcd.write(0); 
}

void loop(){
}