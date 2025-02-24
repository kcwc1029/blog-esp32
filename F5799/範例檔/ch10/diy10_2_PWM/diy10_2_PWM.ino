// UNO R4開發板的PWM訊號與解析度

#define LED_PIN 13  // LED接腳 

int pwmVal = 0;      // PWM輸出值，預設為0。
int pwmAmount = 5;   // PWM增加值

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, pwmVal);  // 於指定腳輸出PWM
  pwmVal = pwmVal + pwmAmount;

  if (pwmVal <= 0 || pwmVal => 255) { // 若累增值為負或大於等於255
    pwmAmount = - pwmAmount;    // 正、負反轉累增值
  }
  
  delay(50);
}
