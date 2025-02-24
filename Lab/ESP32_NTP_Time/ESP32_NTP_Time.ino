#include <WiFi.h>
#include <time.h>

// Wi-Fi 設定
const char *ssid = "你的WiFi名稱";      // Wi-Fi SSID
const char *password = "你的WiFi密碼";  // Wi-Fi 密碼

// NTP 設定
const char *ntpServer = "pool.ntp.org"; // NTP 伺服器
const long  gmtOffset_sec = 28800;      // 時區偏移量（台灣 +8 小時 = 8*3600 秒）
const int   daylightOffset_sec = 0;     // 日光節約時間（若無則設為 0）

void setup() {
    Serial.begin(115200);

    // 連接 Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("連線中");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi 連線成功！");
    Serial.print("IP 位址: ");
    Serial.println(WiFi.localIP());

    // 設定 NTP 時間同步
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
    struct tm timeinfo;
    if (getLocalTime(&timeinfo)) {
        Serial.print("目前時間: ");
        Serial.printf("%04d-%02d-%02d %02d:%02d:%02d\n",
                      timeinfo.tm_year + 1900,
                      timeinfo.tm_mon + 1,
                      timeinfo.tm_mday,
                      timeinfo.tm_hour,
                      timeinfo.tm_min,
                      timeinfo.tm_sec);
    } else {
        Serial.println("❌ 無法取得 NTP 時間");
    }
    
    delay(1000); // 每秒更新一次時間
}
