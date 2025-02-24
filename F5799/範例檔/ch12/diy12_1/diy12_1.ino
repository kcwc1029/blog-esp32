// 動手做12-1：使用超音波感測器製作數位量尺

const byte trigPin = 10;  // 超音波模組的觸發腳
const int echoPin = 9;	  // 超音波模組的接收腳
unsigned long d;  	  // 儲存高脈衝的持續時間

// 自訂ping()函數將傳回unsigned long類型的數值
unsigned long ping() {
  digitalWrite(trigPin, HIGH);	// 觸發腳設定成高電位
  delayMicroseconds(10);		// 持續10微秒
  digitalWrite(trigPin, LOW);	// 觸發腳設定成低電位
  
  return pulseIn(echoPin, HIGH, 23200); // 傳回高脈衝的持續時間
}

void setup() {
  pinMode(trigPin, OUTPUT);  // 觸發腳設定成「輸出」
  pinMode(echoPin, INPUT);   // 接收腳設定成「輸入」
  Serial.begin(9600);		// 初始化序列埠
}

void loop(){
  d = ping() / 58;  	// 把高脈衝時間值換算成公分單位
  Serial.println(String("") + d + "cm");   // 顯示距離
  delay(1000);	      // 等待一秒鐘（每隔一秒測量一次）
}
