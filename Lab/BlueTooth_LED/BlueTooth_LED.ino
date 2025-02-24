// TODO:
// 用手機的藍牙端機軟體（如 Serial Bluetooth Terminal）連接 ESP32，
// 傳送指令來控制 LED 的亮滅。

#include "BluetoothSerial.h"  // 引入藍牙函式庫

// 建立藍牙序列埠物件
BluetoothSerial myBT;

// 定義變數
char incomeData;  // 用於接收資料的變數
const byte LED = 4;  // 定義 LED 連接的 GPIO 腳位

void setup() {
    Serial.begin(9600);   // 設定序列埠通訊速率為 9600
    myBT.begin("BT:01");  // 初始化藍牙，並設定名稱（"BT:01" 可改為自訂名稱）
    pinMode(LED, OUTPUT); // 設定 LED 腳位為輸出模式
}

void loop() {
    // 檢查是否有來自藍牙的資料
    if (myBT.available()) {
        incomeData = myBT.read();  // 讀取手機傳來的資料
        Serial.print("從藍牙接收到：");
        Serial.println(incomeData);  // 在序列監控器顯示接收到的字元

        // 如果接收到 '1'，則開啟 LED
        if (incomeData == '1') {
            digitalWrite(LED, HIGH);  // 讓 LED 亮起
            myBT.println("LED turned ON");  // 回傳訊息給手機
        }

        // 如果接收到 '0'，則關閉 LED
        if (incomeData == '0') {
            digitalWrite(LED, LOW);  // 讓 LED 熄滅
            myBT.println("LED turned OFF");  // 回傳訊息給手機
        }
    }
    delay(20);  // 稍作延遲，避免過度讀取
}