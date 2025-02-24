#include <WiFi.h>        // 引用 Wi-Fi 函式庫
#include <HTTPClient.h>  // 引用 HTTP 客戶端函式庫

HTTPClient http;  // 建立 HTTP 客戶端物件

const char *ssid = "基地台的SSID";      // 無線網路基地台的 SSID
const char *password = "基地台的密碼";  // 無線網路基地台的密碼
String token = "LINE Notify的權杖";    // 權杖（適用於需要驗證的 API）
String msg = "Hello World!";           // 要傳送的訊息內容

void setup() {
    Serial.begin(9600);  // 初始化序列埠通訊
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
    http.begin("https://notify-api.line.me/api/notify");  // 設定 API 端點（可以換成其他 API）

    // NOTE: 設定 HTTP 標頭
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    http.addHeader("Authorization", "Bearer " + token);  // 如果 API 需要驗證，這裡傳遞權杖
    // 送出 POST 請求，並傳遞參數
    int httpCode = http.POST("message=" + msg);

    if (httpCode > 0) {  // 如果回應成功
        String reply = http.getString();  // 取得伺服器回應的內容
        Serial.println(reply);  // 印出伺服器回應
    } else {
        Serial.println("HTTP POST 失敗");
    }

    http.end();  // 結束 HTTP 連線
    delay(5000);  // 每 5 秒發送一次，避免頻率過高
}