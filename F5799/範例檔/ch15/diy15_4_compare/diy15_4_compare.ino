// 比較光電開關接數位腳與類比腳的輸出

byte s1Pin = 8;  // 數位腳 8
byte s2Pin = A0; // 類比腳 A0
int s1Val = 0;
int s2Val = 0;

void setup()
{
  pinMode(s1Pin, INPUT); // 數位腳設定成「輸入」狀態
  Serial.begin(9600);
}
void loop()
{
  s1Val = digitalRead(s1Pin); // 讀取數位輸入值
  s2Val = analogRead(s2Pin);  // 讀取類比輸入值
  Serial.print("s1: ");
  Serial.println(s1Val);
  Serial.print("s2: ");
  Serial.println(s2Val);
  delay(500);
}
