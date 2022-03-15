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
  if(nameset();
}

void nameset()
{
  Serial.print("UID tag :");
  String current_uid = "";
  byte letter;
  for (byte i = 0; i < rfid.uid.size; i++)
  {
    current_uid.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    current_uid.concat(String(rfid.uid.uidByte[i], HEX));
  }
  currnet_name.toUpperCase();
  return currnet_name;
}
// current_name 에다가 방금 읽힌 uid 값을 저장하는 코드 루프로 실행 가능