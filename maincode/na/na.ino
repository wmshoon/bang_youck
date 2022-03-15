char *uidmembers[]{
    "A8N4G300", // MD
    "83A89106", // MR
    "0044115C", // MJ
    "39486228", // MN
    "F3E0D254", // aylin
    "ECCB432E", // alice
    "036EE854", // clara
    "733FE054", // daniel
    "63A5E054", // henry
    "E3C4E754", // ich
    "A360C254", // j
    "23A9DA54", // mail
    "EB9C851F", // wax
    "0CFD0D2C", // nathano
    "33ACD654", // noahn
    "F3D6BC54", // woojin
    "6C6D1F2C", // ronaldo
    "23CDD354", // sofia
    "636EE854", // yuine
    //
    "3CDC1A2C",  // david
    "4C112C2F",  // caleb
    "A747B9D6",  // elena
    "EC60172C",  // emily
    "CACBD73F",  // joshua
    "AC785F49",  // rebecca
    "8C10502F",  // richard
    "5C6F102C",  // edward
    "073EA2D6",  // sarah
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
#incldue < EEPROM.h>
String current_member = "";
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
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
  {
    return;
  }

  Serial.print("Card UID:");

  for (byte i = 0; i < 4; i++)
  {
    Serial.println(rfid.uid.uidByte[i], HEX);
    current_member.concat(String(rfid.uid.uidByte[i], HEX));
  }

  int i = 0;
  while (!current_member == uidmembers[i])
  {
    i++;
  }
  uid = String(uidmembers[i]);
  namee = String(namemembers[i]);
  Serial.print("welcome ");
  Serial.print(namee);
  Serial.print(" !");
  Serial.print(" your UID is ");
  Serial.print(uid);
}
