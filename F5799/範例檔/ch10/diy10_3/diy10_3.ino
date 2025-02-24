// 透過序列埠調整燈光亮度

const byte LED_PIN = 11; 

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {  // 若序列埠收到值…
    String input = Serial.readStringUntil('\n'); 
    int val = input.toInt();
    int pwm = constrain(val, 0, 255);  
    
    Serial.println(String("VAL: ") + val);
    Serial.println(String("PWM: ") + pwm);
    analogWrite(LED_PIN, pwm);
  }
}
