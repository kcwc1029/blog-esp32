// 動手做10-2：隨機數字

void setup(){
  Serial.begin(9600);
  randomSeed( analogRead(A0) );  // 取A0腳的狀態當作種子
  Serial.println( random(128) );  // 隨機數
  Serial.println( random(128) );  // 隨機數
  Serial.println( random(128) );  // 隨機數
}

void loop(){ }