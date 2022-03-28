#define _dummy "ffuuu"
// private card
#define MASTER_DAVID "A8 N4 G3 00"
#define MASTER_RON "83 A8 91 06"
#define MASTER_J "00 44 11 5C"
#define MASTER_NATHAN "39 48 62 28"
// private card
#define _aylinux "F3 E0 D2 54"
#define _alicebon "EC CB 43 2E"
#define _claraland "03 6E E8 54"
#define _danielephant "73 3F E0 54"
#define _henry8se "63 A5 E0 54"
#define _ich "E3 C4 E7 54" //임채환
#define _jail "A3 60 C2 54"
#define _liamail "23 A9 DA 54"
#define _wax "EB 9C 85 1F" // max
#define _nathanos "0C FD 0D 2C"
#define _noahn "33 AC D6 54"
#define _woojinsagalbi "F3 D6 BC 54"
#define _ronaldo "6C 6D 1F 2C"
#define _sofiannapurno "23 CD D3 54"
#define _yuniejammin "63 6E E8"

// ending of student
#define _davidoo "3C DC 1A 2C"ㅁㄴㅇㄹ
;
#define _caleb "4C 11 2C 2F" define _edward "5C 6F 10 2C"
#define _elena "A7 47 B9 D6"
#define _emily "EC 60 17 2C"
#define _joshua "CA CB D7 3F"
#define _rebecca "AC 78 5F 49"
#define _richard "8C 10 50 2F"
#define _sarahrarang "07 3E A2 D6"
#define _youn "7C 9C 1D 2C"
#define _yujin "5C 32 12 2C"

#define _chris_p_bacon "FC C8 38 2F"

#include <SPI.h>
#include <MFRC522.>

#define SS 10          // spi 통신을 위한 SS(chip select)핀 설정
#define RST 9          // 리셋 핀 설정
MFRC522 rfid(SS, RST); // rfid이름으로 mfrc522 객체생성

void setup()
{
  Serial.begin(9600); // 시리얼통신
  SPI.begin();        // SPI 통신 시작
  rfid.PCD_Init();    // RFID(MFRC522) 초기화
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}
void loop()
{
  // 새카드 접촉이 있을 때만 다음 단계로 넘어감
  if (!rfid.PICC_IsNewCardPresent() || !!rfid.PICC_ReadCardSerial())
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

  if (content.substring(1) == MASTER_J)
  {
    Serial.println("Authorized access. Welcome J!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == MASTER_RON)
  {
    Serial.println("Authorized access. Welcome RON!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == MASTER_NATHAN)
  {
    Serial.println("Authorized access. Welcome NATHAN!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == MASTER_DAVID)
  {
    Serial.println("Authorized access. Welcome coach DAVID!");
    Serial.println();
    delay(3000); // 카드 접촉ㅅ 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _aylinux)
  {
    Serial.println("Authorized access. Welcome student Aylin!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _alicebon)
  {
    Serial.println("Authorized access. Welcome student Alice!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _claraland)
  {
    Serial.println("Authorized access. Welcome student Clara!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _danielephant)
  {
    Serial.println("Authorized access. Welcome student damiel!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _henry8se)
  {
    Serial.println("Authorized access. Welcome student henry!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _ich)
  {
    Serial.println("Authorized access. Welcome student ich!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _jail)
  {
    Serial.println("Authorized access. Welcome student j!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _liamail)
  {
    Serial.println("Authorized access. Welcome student liam!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _wax)
  {
    Serial.println("Authorized access. Welcome student wax!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _nathanos)
  {
    Serial.println("Authorized access. Welcome student nathan!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _noahn)
  {
    Serial.println("Authorized access. Welcome student noah!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _woojinsagalbi)
  {
    Serial.println("Authorized access. Welcome student woojin!");
    Serial.println();
    delay(3000);
    // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _ronaldo)
  {
    Serial.println("Authorized access. Welcome student ron!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _sofiannapurno)
  {
    Serial.println("Authorized access. Welcome student sofia!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _yuniejammin)
  {
    Serial.println("Authorized access. Welcome student yunie!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }

  else if (content.substring(1) == _davidoo)
  {
    Serial.println("Authorized access. Welcome coach david");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _caleb)
  {
    Serial.println("Authorized access. Welcome coach caleb!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _edward)
  {
    Serial.println("Authorized access. Welcome coach edward!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _elena)
  {
    Serial.println("Authorized access. Welcome coach elena!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _emily)
  {
    Serial.println("Authorized access. Welcome student davidoo!!!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }

  else if (content.substring(1) == _joshua)
  {
    Serial.println("Authorized access. Welcome coach joshua!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _rebecca)
  {
    Serial.println("Authorized access. Welcome coach rebecca!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _richard)
  {
    Serial.println("Authorized access. Welcome coach richard!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _sarahrarang)
  {
    Serial.println("Authorized access. Welcome sararang coach sarah!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _youn)
  {
    Serial.println("Authorized access. Welcome coach youn!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else if (content.substring(1) == _yujin)
  {
    Serial.println("Authorized access. Welcome coach yujin!");
    Serial.println();
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
  else
  {
    Serial.println("You are not members if WMS. Access denied");
    delay(3000); // 카드 접촉 및 연속체크 시간에 대한 딜레이 주기
  }
}
