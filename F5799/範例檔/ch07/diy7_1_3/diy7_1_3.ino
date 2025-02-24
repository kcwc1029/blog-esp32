// 動手做7-1：全域變數

int x;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  x++;
  Serial.println(x);
  delay(500);
}
