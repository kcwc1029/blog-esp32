// 用大括號細分區域變數

void setup() {
  Serial.begin(9600);
  
  int x = 3;
  if (x==3) {
    byte x = 8;
    Serial.println(x);
  }
  Serial.println(x);
}

void loop() {}