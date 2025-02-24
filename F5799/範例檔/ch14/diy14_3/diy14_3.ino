// 讀取IMU數據

#include <MPU6050_tockn.h>  // 引用MPU6050程式庫
#include <Wire.h>

MPU6050 imu(Wire);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Wire.begin();  // 啟用I2C通訊
  imu.begin();  // 初始化MPU6050晶片
  imu.calcGyroOffsets(true);  // 計算偏移量並顯示偏移值
}

void loop() {
  imu.update();  // 更新感測數據
  Serial.print("getGyroAngleX: ");
  Serial.print(imu.getGyroAngleX());  // 顯示陀螺儀測量的X角度
  Serial.print("\tgetAccAngleX: ");
  Serial.print(imu.getAccAngleX());   // 顯示加速度計測量的X角度
  Serial.print("\tgetAngleX: ");
  Serial.println(imu.getAngleX());     // 顯示融合測量的X角度
}