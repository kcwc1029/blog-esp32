// 動手做20-5：連線NTP伺服器顯示正確日期時間

#include <R4SwRTC.h>   // 取代官方的RTC.h
#include <NTPClient.h>   // NTP前端，負責處理NTP伺服器通訊
#include <WiFiUdp.h>    // 處理UDP通訊協定
#include <WiFiS3.h>	   // 處理WiFi網路連線
#include <Wire.h>		  // 處理I2C連線
#include <LiquidCrystal_PCF8574.h>  // 控制LCD顯示器
#define TMR_FREQ_HZ 100.076    // 程式庫作者建議的計時器頻率值

char *ssid = "Wi-Fi名稱";
char *pass = "Wi-Fi密碼";

LiquidCrystal_PCF8574 lcd(0x27);  // 宣告LCD控制物件

WiFiUDP ntpUdp;   // UDP通訊協定物件
NTPClient timeClient(ntpUdp, 28800);  // NTP伺服器連線物件，UTC+8時區。
r4SwRTC myRTC;   // RTC即時鐘物件
uint32_t lastMillis;  // 紀錄上次執行時的毫秒數

time_t getNTPtime() {  // 傳回從NTP伺服器取得當前時間（秒）
  if (!timeClient.update()) {
    return 0;
  }
  return timeClient.getEpochTime();
}

void lcdZero(byte num) {  // 若時間數字小於10，則在前面補0。
  if (num < 10) {
    lcd.print("0");
  }
  lcd.print(num);
}

void showTime() {    // 在LCD顯示日期和時間
  struct tm *now = myRTC.getTmTime();

  lcd.clear();  // 清除LCD畫面
  lcd.print(now->tm_year + 1900);  // 年
  lcd.print("/");
  lcdZero(now->tm_mon + 1);  // 月，必要時在數字前面補0。
  lcd.print("/");
  lcdZero(now->tm_mday);  // 日

  lcd.setCursor(0, 1);  // 游標移到0行、1列。
  lcdZero(now->tm_hour);  // 時
  lcd.print(":");
  lcdZero(now->tm_min);   // 分
  lcd.print(":");
  lcdZero(now->tm_sec);   // 秒
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);       // 初始化LCD（行數, 列數）
  lcd.setBacklight(255);  // 設定背光亮度（0~255）
  lcd.clear();

  WiFi.begin(ssid, pass);  // 連線到Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    lcd.print(".");
    delay(100);
  }

  lcd.home();  // 清除LCD畫面、游標回到原點
  IPAddress ip = WiFi.localIP();
  lcd.print("IP Address:");  // 在LCD顯示IP位址
  lcd.setCursor(0, 1);  // 游標移到0行、1列。
  lcd.print(ip);

  myRTC.begin(TMR_FREQ_HZ);  // 以指定震盪器頻率初始化微控器的即時鐘

  time_t NTPtime = getNTPtime();  // 取得NTP時間
  if (0 == NTPtime) {
    Serial.println("無法取得NTP時間！");
    while (true) delay(100);
  }

  myRTC.setUnixTime(NTPtime);
  
  delay(2000);  // 暫停2秒
  lastMillis = millis();  // 暫存目前的毫秒數
}

void loop() {
  if (millis() - lastMillis > 1000) {  // 如過了1秒…
    showTime();  // 顯示時間
    lastMillis = millis();
  }
}