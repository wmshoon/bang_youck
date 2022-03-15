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
    Serial.print("Message : ");
    content.toUpperCase();
    // UID값이 아래 값과 같으면 승인 처리
    String current_name = String(content.substring(1));
}