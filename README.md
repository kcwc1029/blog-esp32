成大工科 工程科學暨創新概論 ESP32


## 1. 開發版
- ESP32-S3 開發板 N16R8：[[RWG] ESP32-S3 開發板 N8R2/N16R8 | 蝦皮購物](https://shopee.tw/-RWG-ESP32-S3-%E9%96%8B%E7%99%BC%E6%9D%BF-N8R2-N16R8-i.14363185.22789519649?sp_atk=cfea3333-fd64-41e0-bf09-ddbae1f48bac&xptdk=cfea3333-fd64-41e0-bf09-ddbae1f48bac)
- [WEMOS D1 LOLIN32 V1.0.0 ESP-32 基於WIFI和藍牙 4MB記憶體 外接PH2.0電源插頭 – 台灣物聯科技 TaiwanIOT Studio](https://www.taiwaniot.com.tw/product/wemos-d1-lolin32-v1-0-0-esp-32-%e5%9f%ba%e6%96%bcwifi%e5%92%8c%e8%97%8d%e7%89%994mb-%e8%a8%98%e6%86%b6%e9%ab%94/)


## 2. 常見開發版
- 如果使要使用ESP相關的開發版，你在網路上一定會看到這些
- ESP32
- ESP8266
- D1 mini
- LOLIN D32
- ESP32-S3
![upgit_20250216_1739709906.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250216_1739709906.png)

![upgit_20250216_1739709918.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250216_1739709918.png)

### 2.1. 軟體介面：arduino IDE
安裝教學：[Arduino教學-下載與安裝Arduino IDE，開始撰寫你的第一隻Arduino | 梅問題．教學網](https://www.minwt.com/arduino/22305.html)
### 2.2. USB線插入
![[1739710150904.gif]]
## 3. Lab01：控制LED
```c
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
```




