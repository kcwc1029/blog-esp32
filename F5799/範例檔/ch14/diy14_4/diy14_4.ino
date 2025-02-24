// 透過「序列埠繪圖家」  呈現訊號波形

#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 imu(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  imu.begin();
  imu.calcGyroOffsets(false);  // 校正感測器，但不要顯示訊息。
}

void loop() {
  imu.update();
  Serial.print(String("陀螺儀X:") + imu.getGyroAngleX());
  Serial.print(",");
  Serial.print(String("加速度計X:") + imu.getAccAngleX());
  Serial.print(",");
  Serial.println(String("融合的X:") + imu.getAngleX());
}