#define LED_PIN 2  // LOLIN D32 內建 LED 在 GPIO 2

void setup() {
    Serial.begin(9600);  // 初始化序列埠
    pinMode(LED_PIN, OUTPUT);  // 設定 LED 腳位為輸出
    Serial.println("LOLIN D32 測試開始!");
}

void loop() {
    digitalWrite(LED_PIN, HIGH); // 開啟 LED
    Serial.println("LED ON"); 
    delay(1000); // 等待 1 秒
    
    digitalWrite(LED_PIN, LOW);  // 關閉 LED
    Serial.println("LED OFF");
    delay(1000); // 等待 1 秒
}
