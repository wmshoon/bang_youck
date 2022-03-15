char *uidmembers[]{
    "A8N4G300", // MD
    "83A89106", // MR
    "0044115C", // MJ
    "39486228", // MN
    "F3E0D254", // ay~linux
    "ECCB432E", // alicebon
    "036EE854", // claraland
    "733FE054", // daniel
    "63A5E054", // henry8se
    "E3C4E754", // ich
    "A360C254", // j
    "23A9DA54", // mail
    "EB9C851F", // wax
    "0CFD0D2C", // nathanos
    "33ACD654", // noahn
    "F3D6BC54", // woojinsagalbi
    "6C6D1F2C", // ronaldo
    "23CDD354", // sofia
    "636EE854", // yuinejammin
    //
    "3CDC1A2C",  // davidoo
    "4C112C2F",  // caleb
    "A747B9D6",  // elena
    "EC60172C",  // emily
    "CACBD73F",  // joshua
    "AC785F49",  // rebeccarcenter
    "8C10502F",  // richard
    "5C6F102C",  // edward
    "073EA2D6",  // sarahrarang
    "7C9C1D2C",  // youn
    "5C32122C",  // yujin
    "FCC8382F"}; // chris_p_bacon

char *namemembers[]{
    "MD",            // A8N4G300
    "MR",            // 83A89106
    "MJ",            // 0044115C
    "MN",            // 39486228
    "aylinux",       // F3E0D254
    "alicebon",      // ECCB432E
    "claraland",     // 036EE854
    "daniel",        // 733FE054
    "henry8se",      // 63A5E054
    "ich",           // E3C4E754
    "j",             // A360C254
    "mail",          // 23A9DA54
    "wax",           // EB9C851F
    "nathanos",      // 0CFD0D2C
    "noahn",         // 33ACD654
    "woojinsagalbi", // F3D6BC54
    "ronaldo",       // 6C6D1F2C
    "sofia",         // 23CDD354
    "yuinejammin",   // 636EE854

    "davidoo",        // 3CDC1A2C
    "caleb",          // 4C112C2F
    "elena",          // A747B9D6
    "emily",          // EC60172C
    "joshua",         // CACBD73F
    "rebeccarcenter", // AC785F49
    "richard",        // 8C10502F
    "edward",         // 5C6F102C
    "sarahrarang",    // 073EA2D6
    "youn",           // 7C9C1D2C
    "yujin",          // 5C32122C
    "chris_p_bacon"}; // FCC8382F
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