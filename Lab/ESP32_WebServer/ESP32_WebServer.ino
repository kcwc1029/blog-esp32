#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "CHENG";      // 無線網路基地台的 SSID
const char *password = "87878787";  // 無線網路基地台的密碼

WebServer server(80);  // 建立伺服器物件，監聽 80 號埠（HTTP 預設埠）

// 回應首頁（根目錄）請求
void handleRoot() {
    server.send(200, "text/html; charset=UTF-8", "Hello World!");
}

// 回應 404 未找到的請求
void handleNotFound() {
    server.send(404, "text/plain; charset=UTF-8", "找不到檔案");
}

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);  // 連接 Wi-Fi 網路

    // 等待 Wi-Fi 連線
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.print("\n已連線到基地台：");
    Serial.println(ssid);
    Serial.print("基地台配發給我的 IP 位址：");
    Serial.println(WiFi.localIP());  // 列出 ESP32 取得的 IP

    // router
    server.on("/", handleRoot);           // 註冊首頁請求處理
    server.onNotFound(handleNotFound);    // 註冊 404 未找到處理

    server.begin();
    Serial.println("HTTP 伺服器已啟動");
}

void loop() {
    server.handleClient();  // 處理來自客戶端的請求
}