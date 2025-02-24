// 動手做16-1：使用軟體序列埠程式連接Arduino與藍牙模組

#include <SoftwareSerial.h>
SoftwareSerial BT(9, 10); // 接收, 傳送

char val; // 儲存接收資料的變數

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  BT.begin(9600);
  // 藍牙連線成功後，發佈「準備好了」訊息。
  BT.println("BT is ready!");
}

void loop()
{
  if (BT.available())
  {
    val = BT.read();
    switch (val)
    {
    case '0':                         // 若接收到0...
      digitalWrite(LED_BUILTIN, LOW); // 關閉LED
      break;
    case '1':                          // 若接收到1...
      digitalWrite(LED_BUILTIN, HIGH); // 點亮LED
      break;
    }
  }
}