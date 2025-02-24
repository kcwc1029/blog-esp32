#include "hcsr05.h"

HCSR05 sr05(13, 12);
float distance;

void setup()
{
  Serial.begin(9600);
  Serial.println("ready!");
  Serial.println(ping());
}

void loop()
{
  distance = sr05.ping(); // 讀取障礙物的距離
  Serial.println(String("distance: ") + distance + "cm");
  delay(1000);
}
