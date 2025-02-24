// 每次讀取一行序列資料值

#define LED_PIN 11

void setup() {
  Serial.begin(9600);
  Serial.println("LED is ready!");
}

void loop() {
  String txt;   // 儲存序列字串資料
  int pwm = 0;  // 儲存轉換後的整數值
  
  if (Serial.available()) {
    txt = Serial.readStringUntil('\n');
    pwm = txt.toInt();

    if (pwm > 255) {
      pwm = 255;
    } else if (pwm < 0) {
      pwm = 0;
    }
    
    analogWrite(LED_PIN, pwm);
  }
}
