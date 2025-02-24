// 動手做10-2：隨機數字

void setup(){
  Serial.begin(9600);
  Serial.println( random(128) );  // 始終是39
  Serial.println( random(128) );  // 始終是113
  Serial.println( random(128) );  // 始終是89
}

void loop(){ }
