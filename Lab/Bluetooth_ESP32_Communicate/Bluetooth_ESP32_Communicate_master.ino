// master程式碼
#include "BluetoothSerial.h"  // 引入藍牙函式庫

BluetoothSerial myBT;  // 建立藍牙序列埠物件

// 設定對方 ESP32（從機）的藍牙名稱
const String slaveBT = "BT:01";  // 請改為從機的藍牙名稱
const char *PIN = "1234";        // 預設 PIN 碼（可能是 "0000"）
bool connected;                  // 儲存是否已連線的狀態

void setup() {
    Serial.begin(9600);  // 設定序列埠通訊速率為 9600
    myBT.begin("masterBT", true);  // 啟動藍牙並設為 Master 模式

    Serial.println("藍牙已啟動，進入 Master 模式...");
    Serial.println("連線中...");

    // 嘗試連線到從機（Slave）
    connected = myBT.connect(slaveBT);

    if (connected) {
        Serial.println("連線成功！");
    } else {
        Serial.println("連線失敗，請確認從機是否開啟");
    }
}

void loop() {
    if (connected) {
        myBT.print('1');  // 傳送 '1'，讓從機點亮 LED
        delay(300);

        myBT.print('0');  // 傳送 '0'，讓從機熄滅 LED
        delay(300);
    }
}