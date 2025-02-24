// 動手做14-5：在EEPROM儲存陀螺儀偏移值

#include <MPU6050_tockn.h>  // 引用MPU6050程式庫
#include <Wire.h>
#include <EEPROM.h>   // 引用此程式庫

#define CAL_PIN 13  // 校正接腳

MPU6050 imu(Wire);

float gyroOffsetX;  // 儲存陀螺儀X軸偏移值
float gyroOffsetY;  // 儲存陀螺儀Y軸偏移值
float gyroOffsetZ;  // 儲存陀螺儀Z軸偏移值

// 把X, Y, Z軸偏移值存入EEPROM的自訂函式
void saveIMU_CAL() {
  int addrX = 0;  // X軸偏移值的儲存位址，不一定要從0開始。
  int addrY = addrX + sizeof(float);  // Y軸偏移值的儲存位址
  int addrZ = addrY + sizeof(float);  // Z軸偏移值的儲存位址

  gyroOffsetX = imu.getGyroXoffset();  // 取得X軸偏移值
  gyroOffsetY = imu.getGyroYoffset();  // 取得Y軸偏移值
  gyroOffsetZ = imu.getGyroZoffset();  // 取得Z軸偏移值

  EEPROM.put(addrX, gyroOffsetX);   // X軸偏移值存入EEPROM
  EEPROM.put(addrY, gyroOffsetY);
  EEPROM.put(addrZ, gyroOffsetZ);   

  Serial.print("\n陀螺儀X, Y, Z軸的偏移值：");
  Serial.println(String(gyroOffsetX) + ", " + gyroOffsetY + ", " + gyroOffsetZ);
}

void readIMU_CAL() {   // 讀取EEPROM裡的偏移值
  int addrX =0;
  int addrY = addrX + sizeof(float);
  int addrZ = addrY + sizeof(float);

  EEPROM.get(addrX, gyroOffsetX);
  EEPROM.get(addrY, gyroOffsetY);
  EEPROM.get(addrZ, gyroOffsetZ);

  Serial.print("X, Y, Z軸的偏移值：");
  Serial.println(String(gyroOffsetX) + ", " + gyroOffsetY + ", " + gyroOffsetZ);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);   // 等待序列埠就緒
  pinMode(CAL_PIN, INPUT_PULLUP);  // 啟用上拉電阻
  Wire.begin();                    // 啟用I2C通訊
  imu.begin();                     // 初始化MPU6050晶片

  EEPROM.get(0, gyroOffsetX);  // 嘗試讀取存於位址0的X偏移值

  if (digitalRead(CAL_PIN) == LOW || isnan(gyroOffsetX)) {
    imu.calcGyroOffsets(true);  // 計算偏移量並顯示偏移值

    saveIMU_CAL();  // 寫入陀螺儀偏移值
  } else {
    readIMU_CAL();  // 讀取陀螺儀偏移值
  }

  imu.setGyroOffsets(gyroOffsetX, gyroOffsetY, gyroOffsetZ);  // 套用偏移值
  Serial.println("已套用陀螺儀偏移值");
}

void loop() {
  imu.update();  // 更新感測數據
  Serial.print("陀螺儀X軸：");
  Serial.print(imu.getGyroAngleX());  // 顯示陀螺儀測量的X角度
  Serial.print("\t加速度計X軸：");
  Serial.print(imu.getAccAngleX());  // 顯示加速度計測量的X角度
  Serial.print("\t融合的X軸：");
  Serial.println(imu.getAngleX());  // 顯示融合測量的X角度
}