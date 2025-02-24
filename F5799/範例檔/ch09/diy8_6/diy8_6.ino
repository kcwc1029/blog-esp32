// 製作數位溫濕度顯示器
// 詳細的程式說明，請參閱第8章，8-32頁。

#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // 序列式LCD介面程式庫
#include <DHT.h>         // DHT11感測器程式庫

DHT dht(2, DHT11);      // 宣告DHT程式物件

LiquidCrystal_I2C lcd(0x27, 16, 2);// 宣告LCD程式物件

void setup() {
   dht.begin();       // 開始感測溫濕度
lcd.init();        // 初始化LCD
lcd.backlight();
lcd.setCursor(4, 0);
lcd.print("Temp");
lcd.setCursor(0, 1);
lcd.print("Humidity");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
lcd.setCursor(0, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("from DHT sensor!");
    return;
  }
  lcd.setCursor(9, 0);      // 顯示溫度
  lcd.print(t, 2);          // 2代表顯示小數點後兩位
  lcd.print((char) 0xDF);
  lcd.print("C");

  lcd.setCursor(9, 1);      // 顯示濕度
  lcd.print(h, 2);
  lcd.print("%");

  delay(2000);
}
