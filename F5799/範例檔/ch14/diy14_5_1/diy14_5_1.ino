// 存取EEPROM記憶體

#include <EEPROM.h>  // 引用此程式庫

void setup() {
  Serial.begin(9600);

  int addr = 0; // 起始位址
  int data = 1234; // 整數型態資料

  // 更新EEPROM內容
  EEPROM.update(addr, data >> 8); // 寫入高位元組
  EEPROM.update(addr + 1, data & 0xFF); // 寫入低位元組

  // 讀取EEPROM內容
  int val = (EEPROM.read(addr) << 8) + EEPROM.read(addr + 1);
  Serial.println(String("資料值：") + val);
}

void loop() { }
