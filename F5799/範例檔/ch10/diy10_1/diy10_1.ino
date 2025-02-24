// 動手做10-1：調光器

const byte POT_PIN = A0;		// 類比輸入腳
const byte LED_PIN = 11;		// LED（PWM輸出）腳

void setup() {
  pinMode(LED_PIN , OUTPUT);
}

void loop() {
  int potVal = 0;
  byte pwmVal = 0;

  potVal = analogRead(POT_PIN );
  pwmVal = map(potVal , 0, 1023, 0, 120); 
  analogWrite(LED_PIN , pwmVal );
 }
