// 動手做9-6：製作數位溫濕度顯示器

#include <LiquidCrystal_PCF8574.h> // 序列式LCD介面程式庫
#include <DHT.h>				 // DHT11感測器程式庫

LiquidCrystal_PCF8574 lcd(0x27);// 定義LCD程式物件
DHT dht(2, DHT11);			// 定義DHT程式物件

void setup() {
   dht.begin();       // 開始感測溫濕度
lcd.begin(16, 2);    // 初始化LCD（行數, 列數）
lcd.setBacklight(255);  // 設定背光亮度（0~255）
lcd.clear();
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
