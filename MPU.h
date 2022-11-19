#pragma once

#include <MPU6050_tockn.h>
#include <Wire.h>

#define I2C_SDA 17
#define I2C_SCL 16

TwoWire I2CMPU = TwoWire(0);

MPU6050 mpu6050(I2CMPU);

struct Gyro {
  Gyro() {}

  void begin() {
  I2CMPU.begin(I2C_SDA, I2C_SCL, 100000);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  }

  void start(){
    mpu6050.update();
  }

    int sudut_x(){
    return mpu6050.getAngleX();
  }

  int sudut_y(){
    return mpu6050.getAngleY();
  }

  int sudut_z(){
    return mpu6050.getAngleZ();
  }

};
