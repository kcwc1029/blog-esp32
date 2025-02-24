#include <SoftwareSerial.h>   // 引用程式庫

SoftwareSerial BT(9, 10);  // 連接藍牙模組的軟體序列埠（接收腳, 傳送腳）
char val;              // 儲存接收資料的變數

void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");

  BT.begin(38400);    // 藍牙模組的連線速率，HC-06請改成9600
}

void loop() {
  if (Serial.available()) {  // 若「序列埠監控視窗」收到資料…
    val = Serial.read();
    BT.print(val);       // 轉送到藍牙序列模組
  }

  if (BT.available()) {    // 若藍牙序列模組收到資料…
    val = BT.read();
    Serial.print(val);     // 轉送到「序列埠監控視窗」
  }
}
