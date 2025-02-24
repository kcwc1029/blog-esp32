// 動手做6-3：一個74HC595控制多個七段顯示器

const byte SEG_PIN[2]={8, 9};  // 7段顯示器的控制接腳
const byte NUM_OF_SEG = sizeof(SEG_PIN); // 7段顯示器的數量
int number=0;
byte digits[2] = {0, 0};

const byte dataPin = 2;    // 74HC595序列輸入
const byte latchPin = 3;   // 74HC595暫存器時脈」
const byte clockPin = 4;   // 74HC595序列時脈

unsigned long previousMillis = 0;
const long interval = 1000; 

const byte LEDs[10] = {
  0x7E, 0x30, 0x6D, 0x79, 0x33,
  0x5B, 0x5F, 0x70, 0x7F, 0x73
};

// 每隔一秒數字加1並拆解數字
void counter() {
  unsigned long currentMillis = millis();
  
  // 每隔1秒執行一次底下的條件式內容
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    if (++number > 99) {  // number先加1，再比較
      number = 0;       // 若超過99則歸零
    }
    
    digits[0]= number % 10 ;     // 儲存個位數字
    digits[1]= number / 10 % 10 ;  // 十位數字
  }
}

void display(){
  byte num;

  // 逐一設定每個七段顯示器
  for (byte i=0; i<NUM_OF_SEG; i++){
    num = digits[i];

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDs[num]);
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(SEG_PIN[i], LOW); // 點亮此顯示器
    delay(5);
    
    for (byte j=0; j<NUM_OF_SEG; j++) {
      digitalWrite(SEG_PIN[j], HIGH);  // 關閉所有顯示器
    }
  }
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  for (byte i=0; i<NUM_OF_SEG; i++) {
    pinMode(SEG_PIN[i], OUTPUT);
    digitalWrite(SEG_PIN[i], HIGH);
  }
}

void loop() {
  counter();
  display();
}
