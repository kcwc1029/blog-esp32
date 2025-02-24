#include "BluetoothSerial.h"  // 引入藍牙函式庫

BluetoothSerial myBT;  // 建立藍牙序列埠物件
char incomeData;       // 用於接收來自手機的資料

void setup() {
    myBT.begin("BT:01");  // 初始化藍牙，並設定名稱（"BT:01" 可改為自訂名稱）
}

void loop() {
    // 檢查是否有來自藍牙的資料
    if (myBT.available()) {
        incomeData = myBT.read();  // 讀取手機傳來的資料

        // 如果收到 ASCII 碼 49（即字元 '1'），則執行類比讀取
        if (incomeData == '1') {
            int analogValue = analogRead(33);  // 讀取 GPIO33 上的類比輸入值
            myBT.print("pin 33 analog reading is: ");  // 回傳提示文字給手機
            myBT.println(analogValue);  // 回傳讀取到的類比值給手機
        }
    }
}