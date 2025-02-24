#include <WiFi.h>        // 引用 Wi-Fi 函式庫
#include <HTTPClient.h>  // 引用 HTTP 客戶端函式庫

HTTPClient http;  // 建立 HTTP 客戶端物件

const char *ssid = "CHENG";      // 無線網路基地台的 SSID
const char *password = "87878787";  // 無線網路基地台的密碼

void setup() {
    Serial.begin(115200);  // 初始化序列埠通訊
    Serial.println();  // 分行符號，讓開機訊息更清楚

    WiFi.begin(ssid, password);  // 連接 Wi-Fi

    // 等待 Wi-Fi 連線
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");  // 印出 . 表示正在連線
    }

    Serial.println("\n已連上 Wi-Fi");
}

void loop() {
    http.begin("https://www.google.com.tw");  // 指定要連線的網址
    int httpCode = http.GET();  // 執行 HTTP GET 請求

    if (httpCode > 0) {  // 如果回應成功
        String reply = http.getString();  // 取得伺服器回應的內容
        Serial.println(reply);  // 印出伺服器回應
    } else {
        Serial.println("HTTP 請求失敗");
    }

    http.end();  // 結束 HTTP 連線

    delay(5000);  // 間隔 5 秒再傳送一次，避免頻率過高
}