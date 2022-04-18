//---------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------include----------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
#include <SD.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_MLX90614.h>
#include <RTClib.h>
#include <Wire.h>
//---------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------define-----------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
#define EC_TRIG 123456  // TRIG 핀 설정 (초음파 보내는 핀)
#define EC_ECHO 1234566 // ECHO
#define SS 10
#define RST 9               // reset pin for rfid
#define buzzerPin 142413412 // not defined yet
#define LedPin 12342314     // not defined yet// not defined yet
//---------------------------------------------------------------------------------------------------------------------------------------
File myFile;                                 // SD카드
RTC_DS1307 RTC;                              // RTC클래스 생성
MFRC522 rfid(SS, RST);                       // rfid(SS, RST) defination.
Adafruit_MLX90614 mlx = Adafruit_MLX90614(); // temperature sensor.
//---------------------------------------------------------------------------------------------------------------------------------------
char *UIDmembers[]{
    " 83 9E E0 54",  // MD 83 9E E0 54
    " 83 A8 91 06",  // MR 83 A8 91 06
    " 00 44 11 5C",  // MJ 00 44 11 5C
    " 39 48 62 28",  // MN 39 48 62 28
    " F3 E0 D2 54",  // aylin F3 E0 D2 54
    " EC CB 43 2E",  // alice EC CB 43 2E
    " 03 6E E8 54",  // clara 03 6E E8 54
    " 73 3F E0 54",  // daniel 73 3F E0 54
    " 63 A5 E0 54",  // henry 63 A5 E0 54
    " E3 C4 E7 54",  // ich E3 C4 E7 54
    " A3 60 C2 54",  // j A3 60 C2 54
    " 23 A9 DA 54",  // mail 23 A9 DA 54
    " EB 9C 85 1F",  // wax EB 9C 85 1F
    " 0C FD 0D 2C",  // nathanos 0C FD 0D 2C
    " 33 AC D6 54",  // noahn 33 AC D6 54
    " F3 D6 BC 54",  // woojin F3 D6 BC 54
    " 6C 6D 1F 2C",  // ronaldo 6C 6D 1F 2C
    " 23 CD D3 54",  // sofia 23 CD D3 54
    " 63 FC BE 54",  // yuine 63 6E E8 54
    " 3C DC 1A 2C",  // david 3C DC 1A 2C
    " 4C 11 2C 2F",  // caleb 4C 11 2C 2F
    " A7 47 B9 D6",  // elena A7 47 B9 D6
    " EC 60 17 2C",  // emily EC 60 17 2C
    " CA CB D7 3F",  // joshua CA CB D7 3F
    " AC 78 5F 49",  // rebecca AC 78 5F 49
    " 8C 10 50 2F",  // richard 8C 10 50 2F
    " 5C 6F 10 2C",  // edward 5C 6F 10 2C
    " 07 3E A2 D6",  // sarah 07 3E A2 D6
    " 7C 9C 1D 2C",  // youn 7C 9C 1D 2C
    " 5C 32 12 2C",  // yujin 5C 32 12 2C
    " FC C8 38 2F"}; // chris_p_bacon FC C8 38 2F
char *NAMEmembers[]{
    "MD",             // 83 9E E0 54
    "MR",             // 83 A8 91 06
    "MJ",             // 00 44 11 5C
    "MN",             // 39 48 62 28
    "aylin",          // F3 E0 D2 54
    "elice",          // EC CB 43 2E
    "clara",          // 03 6E E8 54
    "daniel",         // 73 3F E0 54
    "henry",          // 63 A5 E0 54
    "ich",            // E3 C4 E7 54
    "j",              // A3 60 C2 54
    "liam",           // 23 A9 DA 54
    "max",            // EB 9C 85 1F
    "nathan",         // 0C FD 0D 2C
    "noahn",          // 33 AC D6 54
    "woojin",         // F3 D6 BC 54
    "ron",            // 6C 6D 1F 2C
    "sofia",          // 23 CD D3 54
    "yuine",          // 63 6E E8 54
    "david",          // 3C DC 1A 2C
    "caleb",          // 4C 11 2C 2F
    "elena",          // A7 47 B9 D6
    "emily",          // EC 60 17 2C
    "joshua",         // CA CB D7 3F
    "rebecca",        // AC 78 5F 49
    "richard",        // 8C 10 50 2F
    "edward",         // 5C 6F 10 2C
    "sarahrarang",    // 07 3E A2 D6
    "youn",           // 7C 9C 1D 2C
    "yujin",          // 5C 32 12 2C
    "chris_p_bacon"}; // FC C8 38 2F ##========== 0 to 30 ==========#const PROGMEM char *hello_message_all[]{
// char *hello_message_all[]{
//     "yo! wasup",
//     "hello",
//     "hi",
//     "good to see you",
//     "glad to see you",
//     "welcome",
//     "welcome back",
//     "nice to see you"};
// char *hello_message_goodbye_late[]{
//     "see you later",
//     "good bye",
//     "i am working... and u are going",
//     "bye",
//     "have a good night"};
// char *hello_message_goodbye_early[]{
// "see you later",
// "good bye",
// "i am working... and u are going",
// "bye"};
float current_temp;
//---------------------------------------------------------------------------------------------------------------------------------------
void setup()
{
start:
    Serial.begin(9600);
    pinMode(EC_TRIG, OUTPUT);
    pinMode(EC_ECHO, INPUT);
    pinMode(10, OUTPUT);
    if (!SD.begin(4))
    {
        Serial.println("SD card initialization failed!");
        Serial.println("returning to setup");
        delay(1000);
        goto start;
    }
    Serial.println("SD card initialization done.");
    Wire.begin();
    SPI.begin();
    RTC.begin();
    RTC.adjust(DateTime(__DATE__, __TIME__));
    rfid.PCD_Init();
    mlx.begin();
    Serial.println("System is ready to go0000!");
}
void loop()
{
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    {
        return;
    }
    Beep();
    String current_uid = "";
    byte letter;
    for (byte i = 0; i < rfid.uid.size; i++)
    {
        current_uid.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
        current_uid.concat(String(rfid.uid.uidByte[i], HEX));
    }
    current_uid.toUpperCase();
    for (int i = 0; i < 31; i++)
    {
        if (current_uid == UIDmembers[i]
        {
            while (!)
                float current_temp = mlx.readObjectTempC();
            if (current_temp < 37.5)
            {
                WriteToLCD(NAMEmembers[i]);
                WriteToSDcard(NAMEmembers[i], current_temp);
            }
            else
            {
                Beep();
            }
        }
    }
}

String WriteToLCD(String name)
{
    // LCD.write("hello " + name + "welcome here!");
    // LCD.clear();
}
void Beep()
{
    digitalWrite(buzzerPin, HIGH);
    delay(10);
    digitalWrite(buzzerPin, LOW);
    delay(10);
}
void blinkLED()
{
    digitalWrite(buzzerPin, HIGH);
    delay(10);
    digitalWrite(buzzerPin, LOW);
    delay(10);
}
void WriteToSDcard(String current_name, float temperature) // i equals number of members, b equals temp of object
{
    String current_info = "";
    current_info.concat("NAME : ");
    current_info.concat(current_name);
    current_info.concat("    DATE: ");
    current_info.concat(returnDate());

    myFile = SD.open(current_info, FILE_WRITE);

    if (myFile)
    {
        myFile.print("DATE: ");
        myFile.print(returnDayAndHour());
        myFile.print("  TEMP: ");
        myFile.println(temperature);
        myFile.close();
    }
}
String returnDate() // return the date string for human.// EX)  year: 2022 month : 4 day : 13 hour : 21 minute : 12 second : 42
{
    String Now = "";
    DateTime now = RTC.now();
    Now.concat("year :");
    Now.concat(now.year());
    Now.concat(" month :");
    Now.concat(now.month());
    Now.concat(" day :");
    Now.concat(now.day());
    Now.concat(" hour :");
    Now.concat(now.hour());
    Now.concat(" minute :");
    Now.concat(now.minute());
    Now.concat(" second :");
    Now.concat(now.second());
    return (Now);
}
String returnDayAndHour()
{
    String Now = "";
    DateTime now = RTC.now();
    Now.concat("day :");
    Now.concat(now.day());
    Now.concat(" hour :");
    Now.concat(now.hour());
    return (Now);
}