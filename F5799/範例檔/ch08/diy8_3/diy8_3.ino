// 動手做8-3：拍手控制開關

int micPin = A0;        // 麥克風訊號輸入腳
int micVal = 0;         // 麥克風音量值
boolean toggle = false; // LED 的狀態，預設為不亮

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  micVal = analogRead(micPin);

  if (micVal > 500)
  { // 如果音量大於 500 ...
    Serial.println(micVal);
    toggle = !toggle;

    if (toggle)
    {
      digitalWrite(LED_BUILTIN, HIGH); // LED 點亮
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW); // LED 熄滅
    }
  }
}
