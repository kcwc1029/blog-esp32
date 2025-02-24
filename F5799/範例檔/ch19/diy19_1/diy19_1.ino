// 動手做19-1：操控三態多工LED

byte pins[] = {  // 定義接腳
  10, // 定義列 0 腳 
  11, // 定義列 1 腳
  9   // 定義列 2 腳
};

byte totalPins = sizeof(pins); // 接腳總數

int modes[6][3] = {
  {1, 0, -1},
  {0, 1, -1},
  {1, -1, 0},
  {0, -1, 1},
  {-1, 1, 0},
  {-1, 0, 1}
};

int totalModes = sizeof(modes) / sizeof(modes[0]);  

void setup() { }  // setup不含程式碼

void loop() {
  for (byte i = 0; i < totalModes; i++) {
    for(byte j = 0; j < totalPins;j++) {
      if(modes[i][j] < 0)
        pinMode(pins[j], INPUT);
      else {
        pinMode(pins[j], OUTPUT);
        digitalWrite(pins[j], modes[i][j]);
      }
    }
    delay(500);
  }
}