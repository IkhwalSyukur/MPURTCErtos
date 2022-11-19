#include "MPU.h"
#include "RTC.h"

Gyro gyro;
RTC myrtc;

int angle_treshold;
int x, y, z;
int invert;
String harin;
String jamn;
String menitn;
String detikn;
String date;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  gyro.begin();
  myrtc.begin();

  xTaskCreate(gyro_task, "gyro task", 2048, NULL, 1, NULL);
  xTaskCreate(myrtc_task, "rtc task", 2048, NULL, 1, NULL);

  
  invert = angle_treshold - angle_treshold * 2;
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Sudut x : " + String (x) + ", Sudut y : " + String(y) + ", Sudut z : " + String (z));
Serial.println(date);
}

void gyro_task(void *parameter) {
  for (;;) {
    gyro.start();
    x = gyro.sudut_x();
    y = gyro.sudut_y();
    z = gyro.sudut_z();
    harin = gyro.daten();
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
}

void myrtc_task(void *parameter) {
  for (;;) {
    date=myrtc.daten();
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
}
