// 電晶體馬達控制與調速器

byte potPin = A0;    // 類比輸入腳位（接10KΩ可變電阻）
byte motorPin = 5;  // 類比輸出腳位（接電晶體馬達控制電路）
int potspeed = 0;   // 類比輸出值
byte val = 0;     // 儲存類比範圍轉換值

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  potspeed = analogRead(potPin);
  val = map(potspeed, 0, 1023, 0, 255);
  analogWrite(motorPin, val);
}
