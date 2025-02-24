#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

// 📡 Wi-Fi 設定
const char* ssid = "CHENG";       // Wi-Fi SSID
const char* password = "87878787"; // Wi-Fi 密碼

// 🌡️ DHT11 感測器設定
#define DHTPIN 5          // DHT11 連接到 ESP32 的 GPIO 5
#define DHTTYPE DHT11     // 使用 DHT11（如果是 DHT22，請改成 DHT22）
DHT dht(DHTPIN, DHTTYPE);

// 🌐 建立 Web Server（監聽 Port 80）
WebServer server(80);

void handleRoot() {
    // 讀取 DHT11 感測器數據
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    float heatIndex = dht.computeHeatIndex(temperature, humidity, false);

    // 檢查是否讀取成功
    if (isnan(humidity) || isnan(temperature)) {
        server.send(500, "text/plain", "❌ 無法讀取 DHT11 感測數據");
        return;
    }

    // 📄 HTML 內容
    String html = "<!DOCTYPE html>";
    html += "<html lang='zh-TW'><head><meta charset='UTF-8'>";
    html += "<title>ESP32 DHT11 Web Server</title>";
    html += "<style>body { font-family: Arial; text-align: center; margin: 40px; }";
    html += "h1 { color: #007BFF; } p { font-size: 24px; }</style>";
    html += "<meta http-equiv='refresh' content='2'></head><body>";
    html += "<h1>ESP32 溫濕度監測</h1>";
    html += "<p>💧 濕度: " + String(humidity) + "%</p>";
    html += "<p>🌡️ 溫度: " + String(temperature) + "°C</p>";
    html += "<p>🔥 體感溫度: " + String(heatIndex) + "°C</p>";
    html += "<p><small>數據每 2 秒自動更新</small></p>";
    html += "</body></html>";

    // 發送 HTML 給客戶端
    server.send(200, "text/html", html);
}

void setup() {
    Serial.begin(115200);
    Serial.println("\n🚀 ESP32 啟動中...");

    // 📡 連接 Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\n✅ Wi-Fi 連線成功！");
    Serial.print("📡 ESP32 IP 地址: ");
    Serial.println(WiFi.localIP());

    // 🌡️ 啟動 DHT11
    dht.begin();

    // 🌐 啟動 Web Server
    server.on("/", handleRoot);
    server.begin();
    Serial.println("🌍 Web 伺服器已啟動！");
    Serial.print("🔗 在瀏覽器輸入: http://");
    Serial.println(WiFi.localIP());
}

void loop() {
    server.handleClient(); // 處理 Web 伺服器請求
}
