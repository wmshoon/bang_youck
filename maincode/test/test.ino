// define as "member number"
//  *undefined equals that the modules are not delivered yet.
#define _dummy "asdfasdfasd"
// private card
#define MASTER_DAVIDOOOOO "undefined"
#define MASTER_RONALDO "CA CB D7 3F"
#define MASTER_J "00 44 11 5C"
#define MASTER_NATHANOS "39 48 62 28"
// private card
#define _aylinux "udefined"
#define _alicebon "udefined"
#define _claraland "undefined"
#define _danielephant "udefined"
#define _henry8se "udefined"
#define _ichibab "udefined" //임채환
#define _j "undefined"
#define _liamail "undefined"
#define _maxrange "udefined"
#define _nathanos "udefined"
#define _noahn "udefined"
#define _woojinsagalbi "udefined"
#define _ronaldo "undefined"
#define _sofiannapurna "udefined"
#define _yuniejjajang "udefined"

// ending of student
#define _david "undefined"
#define _caleb "undefined"
#define _edward "undefined"
#define _elena "undefined"
#define _emily "undefined"
#define _joshua "undefined"
#define _rebecca "undefined"
#define _richard "undefined"
#define _sarah "undefined"
#define _youn "undefined"
#define _yujin "undefined"

#define _chris "undefined"

int members[28] = {
    _dummy,         //    0
    _aylinux,       //    1
    _alicebon,      //    2
    _claraland,     //    3
    _danielephant,  //    4
    _henry8se,      //    5
    _ichibab,       //    6
    _j,             //    7
    _liamail,       //    8
    _maxrange,      //    9
    _nathanos,      //    10
    _noahn,         //    11
    _woojinsagalbi, //    12
    _ronaldo,       //    13
    _sofiannapurna, //    14
    _yuniejjajang,  //    15

    _david,   //    16
    _caleb,   //    17
    _chris,   //    18x
    _edward,  //    19
    _elena,   //    20
    _emily,   //    21
    _joshua,  //    22
    _rebecca, //    23
    _richard, //    24
    _sarah,   //    25
    _youn,    //    26
    _yujin};  //    27

//     for (byte i = 0, i < sizeof(array), i++) {}

#include <SPI.h>
#include <MFRC522.h>

#define SS 10          // spi 통신을 위한 SS(chip select)핀 설정
#define RST 9          // 리셋 핀 설정
MFRC522 rfid(SS, RST); // rfid이름으로 mfrc522 객체생성

void setup()
{
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
    Serial.println("system is good");
    Serial.println();
}

void loop()
{
    if (!rfid.PICC_IsNewCardPresent())
    {
        return;
    }
    if (!rfid.PICC_ReadCardSerial())
    {
        return;
    }
    Serial.print("UID tag :");
    String content = "";
    byte letter;
    for (byte i = 0; i < rfid.uid.size; i++)
    {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
        content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    Serial.println();
        content.toUpperCase();
    // UID값이 아래 값과 같으면 승인 처리
    String current_name = String(content.substring(1));
}

// String(rfid.uid.uidByte[i], HEX) 이게 그거임 uid 불러오기
//대충 짠 테스트. 사용할 일은 없어 보임.
