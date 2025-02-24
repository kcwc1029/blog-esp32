// 光電子琴製作

const byte SND_PIN = 11; // 蜂鳴器的接腳
const byte sPins[] = {
    A0, A1, A2};                       // 光電感測器的接腳編號
const int pitches[] = {659, 523, 784}; // 聲音的頻率
void setup()
{
  pinMode(SND_PIN, OUTPUT); // 蜂鳴器接腳設定成「輸出」
}

void loop()
{
  int n = -1;

  for (byte i = 0; i < 3; i++)
  { // 依次讀取三個接腳的數值
    int val = analogRead(sPins[i]);
    if (val > 500)
    {        // 如果類比值大於 500，代表碰到黑色
      n = i; // 記錄接腳的索引編號
      break; // 終止迴圈
    }
  }

  if (n != -1)
  {                            // 只要 n 變數值不是-1，代表有接腳感測到黑色
    tone(SND_PIN, pitches[n]); // 根據該腳的索引值，發出對應的聲音
  }
  else
  {                  // 否則...（所有感測器都讀取到白色）
    noTone(SND_PIN); // 停止發聲
  }
}
