// 動手做20-4：觸控功能鍵

#include <Keyboard.h>
#include <R4_Touch.h>
#define THRESHOLD 4659  // 觸控感測開、關的臨界值

TouchSensor ts;  // 宣告碰觸感測器物件

// 觸控感測器的參數
ctsu_pin_settings_t tsSettings = { .div = CTSU_CLOCK_DIV_18, .gain = CTSU_ICO_GAIN_100, .ref_current = 0, .offset = 75, .count = 3 };
const byte tsPin = 20;   // 觸控腳編號，20代表愛心。
bool lastTouch = false;  // 上次觸控狀態，預設為「未觸控」。
bool ledState = LOW;     // LED燈的狀態

void setup() {
  Serial.begin(9600);
  while (!Serial) ;  // 等待序列埠就緒
  pinMode(LED_BUILTIN, OUTPUT);  // 內建的LED腳模式設為「輸出」
  ts.begin(tsPin, THRESHOLD);   // 初始化觸控腳，傳入腳位和臨界值參數。
  ts.applyPinSettings(tsSettings); // 套用觸控感測器的參數
  TouchSensor::start();  // 啟用電容觸控
  Keyboard.begin();      // 啟用USB鍵盤
}

void loop() {
  bool touch = ts.read();  // 讀取觸控狀態，傳回true代表感應到觸控。

  if (touch != lastTouch) {
    if (touch) {
      Serial.println("碰到了！");
      ledState = !ledState;   // 反相LED燈的狀態
      digitalWrite(LED_BUILTIN, ledState); // 點亮或關閉LED

      // 按下Win+R鍵，啟動chrome瀏覽器開啟網頁。
      Keyboard.press(KEY_LEFT_GUI);  // 按著左Win鍵
      Keyboard.press('r');            // 按著‘r’鍵
      delay(100);
      Keyboard.releaseAll();   // 放開全部鍵
      delay(500);
      Keyboard.println("chrome https://swf.com.tw"); // 輸入文字
      delay(100);
    } else {
      Serial.println("放開");
    }
    lastTouch = touch;  // 紀錄本次觸控狀態
  }
}
