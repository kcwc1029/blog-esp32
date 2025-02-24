// 動手做14-6：使用IMU感測器控制伺服馬達

#include <MPU6050_tockn.h>  // 引用MPU6050程式庫
#include <Servo.h>
#include <Wire.h>
#include <EEPROM.h>

#define CAL_PIN 13  // 校正接腳
#define SERVO_X_PIN 8  // 伺服馬達X接腳
#define SERVO_Y_PIN 9  // 伺服馬達Y接腳

MPU6050 imu(Wire);
Servo servoX, servoY;  // 宣告兩個伺服馬達物件

int valX, posX;
int valZ, posZ;  // 暫存IMU模組的Z軸值

float gyroOffsetX;
float gyroOffsetY;
float gyroOffsetZ;

void saveIMU_CAL() {
  int addrX = EEPROM.begin();
  int addrY = addrX + sizeof(float);
  int addrZ = addrY + sizeof(float);

  gyroOffsetX = imu.getGyroXoffset();
  gyroOffsetY = imu.getGyroYoffset();
  gyroOffsetZ = imu.getGyroZoffset();

  EEPROM.put(addrX, gyroOffsetX);
  EEPROM.put(addrY, gyroOffsetY);
  EEPROM.put(addrZ, gyroOffsetZ);

  Serial.print("\n陀螺儀X, Y, Z軸的偏移值：");
  Serial.println(String(gyroOffsetX) + ", " + gyroOffsetY + ", " + gyroOffsetZ);
}

void readIMU_CAL() {
  int addrX = EEPROM.begin();
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
  while (!Serial);

  servoX.attach(SERVO_X_PIN);   // 設定伺服馬達的接腳
  servoY.attach(SERVO_Y_PIN);

  Serial.println(String("\nEEPROM大小：") + EEPROM.length());
  pinMode(CAL_PIN, INPUT_PULLUP);  // 啟用上拉電阻
  Wire.begin();                    // 啟用I2C通訊
  imu.begin();                     // 初始化MPU6050晶片

  EEPROM.get(0, gyroOffsetX);  // 嘗試讀取X偏移植

  if (digitalRead(CAL_PIN) == LOW || isnan(gyroOffsetX)) {
    imu.calcGyroOffsets(true);  // 計算偏移量並顯示偏移值

    saveIMU_CAL();  // 儲存偏移值
  } else {
    readIMU_CAL();  // 讀取偏移值
  }

  imu.setGyroOffsets(gyroOffsetX, gyroOffsetY, gyroOffsetZ);  // 套用偏移值
  Serial.println("已套用陀螺儀偏移值");
}

void loop() {
  imu.update();
  valX = imu.getAngleX();
  valZ = imu.getAngleZ();   // 讀取Z軸的融合角度值

  posX = map(valX, -150, 150, 0, 180);
  posZ = map(valZ, -150, 150, 0, 180);
  servoX.write(posX);
  servoY.write(posZ);   // 用Z軸值設定伺服馬達的角度
  delay(15);
}
