#pragma once

#include <Wire.h>
#include "RTClib.h"

#define I2C_SDA 17
#define I2C_SCL 16

TwoWire I2CRTC = TwoWire(0);

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

struct RTC {
  RTC() {}

    void begin(){
          I2CRTC.begin(I2C_SDA, I2C_SCL, 100000);
          bool status;
          status = rtc.begin(&I2CRTC);
          if (! status) {
               Serial.println("Couldn't find RTC");
               while (1);
          }
       rtc.adjust(DateTime(__DATE__, __TIME__));
//    rtc.adjust(DateTime(2022,11,2,12,1 9,00));
      }
  String daten(){
    DateTime now = rtc.now();
    return String(daysOfTheWeek[now.dayOfTheWeek()]) + "," + String(now.hour(), DEC) + ":" + String(now.minute(), DEC) + ":" + String(now.second(), DEC);
  }
};
