// parseInt()方法解析整數

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500); // 等待時間設為500毫秒
}

void loop() {
  while (Serial.available()>0) {  // 持續直到所有序列輸入值都處理完畢
    int val = Serial.parseInt(SKIP_ALL, ',');  // 忽略千位分隔符號（,）
    Serial.println(val); 
  }
}
