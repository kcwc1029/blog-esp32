#include <WiFi.h>

const char *ssid = "";      // 無線網路基地台的 SSID
const char *password = "";  // 無線網路基地台的密碼

void setup() {
    Serial.begin(9600);  // 初始化序列埠通訊
    WiFi.begin(ssid, password);  // 連接 Wi-Fi 網路

    while (WiFi.status() != WL_CONNECTED) {  // 當狀態不是已連線
        delay(500);  // 等待 0.5 秒
        Serial.print(".");  // 印出一個點提示進度
    }

    Serial.println("\n已連上 Wi-Fi");

    // 顯示 Wi-Fi 相關資訊
    Serial.print("我的 IP 位址：");
    Serial.println(WiFi.localIP());  // 印出 ESP32 取得的 IP 位址

    Serial.print("子網路遮罩：");
    Serial.println(WiFi.subnetMask());  // 印出子網路遮罩

    Serial.print("閘道器位址：");
    Serial.println(WiFi.gatewayIP());  // 印出閘道器 IP 位址

    Serial.print("DNS 位址：");
    Serial.println(WiFi.dnsIP());  // 印出 DNS 位址
}

void loop() {
    // 這裡可以加入其他程式碼，例如 Wi-Fi 連線後的網路操作
}