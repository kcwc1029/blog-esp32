#include <WiFi.h>

// 設定 AP 名稱與密碼
const char *ssid = "ESP32基地台";
const char *password = "12345678";

void setup() {
    Serial.begin(115200);  // 初始化序列埠通訊

    // 啟動 AP，若失敗則不斷重試
    while (!WiFi.softAP(ssid, password)) {};

    Serial.println("\nAP 啟動成功");  // 顯示 AP 啟動成功的訊息

    // 顯示 AP 的 IP 位址（ESP32 會自動指派）
    Serial.print("我的 IP 位址：");
    Serial.println(WiFi.softAPIP());
}

void loop() {
    // 這裡可以加入其他程式碼，例如管理連線的設備或提供服務
}
