// 動手做7-1：靜態變數

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  static int x;
  x ++;
  Serial.println(x);
  delay(500);
}
