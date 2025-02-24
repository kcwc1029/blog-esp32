// 動手做5-2：從序列埠控制 LED 開關，使用switch..case

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
    switch (val)
    {
    case '0':
      digitalWrite(LED, LOW);
      break;
    case '1':
      digitalWrite(LED, HIGH);
      break;
    }
  }
}