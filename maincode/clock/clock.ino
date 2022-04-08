#include <RTClib.h> // RTC 기본 라이브러리
#include <Wire.h>   // i2c 통신 라이브러리
RTC_DS1307 RTC;     // RTC클래스 생성

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    RTC.adjust(DateTime(__DATE__, __TIME__));
    nowtime();
}

void loop()
{
    Serial.println(ReturnTime());
}

String ReturnTime()
{
    String Now = "";
    DateTime now = RTC.now();
    Now.concat("year:");
    Now.concat(now.year());
    Now.concat(" month:");
    Now.concat(now.month());
    Now.concat(" day:");
    Now.concat(now.day());
    Now.concat(" hour:");
    Now.concat(now.hour());
    Now.concat(" minute:");
    Now.concat(now.minute());
    Now.concat(" second:");
    Now.concat(now.second());
    return (Now);
}