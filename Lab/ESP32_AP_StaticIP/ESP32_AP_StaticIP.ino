#include <WiFi.h>

IPAddress local_IP(192, 168, 4, 100);  // 設定 ESP32 當 AP 時的 IP 位址
IPAddress gateway(192, 168, 4, 100);  // 設定此網路的閘道器 IP 位址（一般與 local_IP 相同）
IPAddress subnet(255, 255, 255, 0);  // 設定此網路的子網路遮罩

// 設定 AP 名稱與密碼
const char *ssid = "ESP32基地台";
const char *password = "12345678";

void setup() {
    Serial.begin(115200);  // 初始化序列埠通訊

    // 設定 AP 位址（本機 IP、閘道器 IP、子網路遮罩）
    WiFi.softAPConfig(local_IP, gateway, subnet);

    // 啟動 AP，若失敗則不斷重試
    while (!WiFi.softAP(ssid, password)) {};

    Serial.println("\nAP 啟動成功");  // 顯示 AP 啟動成功的訊息

    // 顯示 AP 的 IP 位址
    Serial.print("我的 IP 位址：");
    Serial.println(WiFi.softAPIP());
}

void loop() {
    // 這裡可以加入其他程式碼，例如管理連線的設備或提供服務
}