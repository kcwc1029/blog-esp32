// 動手做5-2：從序列埠控制 LED 開關

char val;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.print("Welcome to Arduino!");
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    if (val == '1')
    {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED ON");
    }
    else if (val == '0')
    {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED OFF");
    }
  }
}