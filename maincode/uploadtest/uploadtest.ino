#include <SPI.h>
#include <MFRC522.h>

void setup()
{
    Serial.begin(9600);
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
        content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    Serial.println(content);
    // UID값이 아래 값과 같으면 승인 처리
    String current_name = String(content.substring(1));
}