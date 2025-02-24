#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi 設定
const char* ssid = "CHENG";  // WiFi名稱
const char* password = "87878787";  // WiFi密碼

WebServer server(8080);  // 使用 Port 8080，避免部分 Wi-Fi 封鎖 Port 80
const int ledPin = 15;     // 連接 LED 的腳位 (LOLIN D32 可用 5, 2, 4)

// 🔹 關閉 Wi-Fi 省電模式，避免連線問題
void disableWiFiSleep() {
  WiFi.setSleep(false);
}

// 🔹 伺服器首頁 (HTML 按鈕控制 LED)
void handleRoot() {
  server.send(200, "text/html",
              "<h1>ESP32 LED Control</h1>"
              "<p><a href='/H'><button>OPEN LED</button></a></p>"
              "<p><a href='/L'><button>CLOSE LED</button></a></p>");
}

// 🔹 開啟 LED
void handleLEDOn() {
  digitalWrite(ledPin, HIGH);
  Serial.println("🔵 LED OPEN");
  server.send(200, "text/plain", "LED opened");
}

// 🔹 關閉 LED
void handleLEDOff() {
  digitalWrite(ledPin, LOW);
  Serial.println("⚫ LED close");
  server.send(200, "text/plain", "LED closed");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  disableWiFiSleep();  // 關閉 Wi-Fi 省電模式

  Serial.println("\n🚀 連接到 Wi-Fi...");
  WiFi.begin(ssid, password);

  int connect_attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    connect_attempts++;
    if (connect_attempts > 20) {  // 10秒超時
      Serial.println("\n❌ Wi-Fi 連線失敗！請檢查 SSID 與密碼。");
      return;
    }
  }

  Serial.println("\n✅ Wi-Fi 連線成功!");
  Serial.print("📡 你的 ESP32 IP 地址: ");
  Serial.println(WiFi.localIP());

  // 🔹 設定 HTTP 路由
  server.on("/", handleRoot);
  server.on("/H", handleLEDOn);
  server.on("/L", handleLEDOff);

  server.begin();
  Serial.println("🌐 Web 伺服器已啟動！");
  Serial.println("🔎 請在瀏覽器輸入: http://" + WiFi.localIP().toString() + ":8080");
  Serial.println("🔎 或使用: http://" + WiFi.localIP().toString() + ":8080/H 來開啟 LED");
  Serial.println("🔎 或使用: http://" + WiFi.localIP().toString() + ":8080/L 來關閉 LED");
}

void loop() {
  Serial.println("⌛ 等待客戶端連線...");
  server.handleClient();
  delay(1000);  // 降低 CPU 使用率
}
