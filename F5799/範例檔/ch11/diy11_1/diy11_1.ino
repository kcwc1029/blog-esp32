// 動手做11-1：演奏一段瑪莉歐旋律，使用 #define 巨集指令替換資料。

#define E5 659  // 定義音名和頻率
#define C5 523
#define G5 784
#define SP_PIN 11  // 定義蜂鳴器的接腳

int tempo = 200;    // 節拍
int beatNote = 2;       // 一拍的音符
long wholenote = (60000 * beatNote) / tempo;

int melody[][2] = {  // 旋律資料
  {E5, 4}, {E5, 4}, {0, 4}, {E5, 4}, {0, 4}, {C5, 4}, {E5, 4}, {0, 4}, {G5, 4}, {0, 4}, {0, 2}
};

int noteTotal = sizeof(melody) / sizeof(melody[0]);
int noteIndex = 0;  // 旋律陣列的索引，從0開始。

void setup() {
  pinMode (SP_PIN, OUTPUT);
}

void loop() {
  int noteFreq = melody[noteIndex][0];  // 音高（Hz頻率）
  int noteDuration = wholenote / melody[noteIndex][1]; 

  if (noteFreq!= 0) {  // 若音高不是0…
    tone(SP_PIN, noteFreq);
    delay(noteDuration * 0.9);
    noTone(SP_PIN);
    delay(noteDuration * 0.1);
  } else {
    noTone(SP_PIN);
    delay(noteDuration);
  }

  noteIndex ++;  // 旋律索引值+1

  if (noteIndex == noteTotal) {
    noteIndex = 0;   // 索引值歸0
    noTone(SP_PIN);  // 停止發聲
    delay(1000);
  }
}