#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_MLX90614.h>

#define SS 10
#define RST 9
#define buzzerPin 5

char *UIDmembers[]{
    "83 9E E0 54",   // MD 83 9E E0 54
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
    "aylinux",        // F3 E0 D2 54
    "alicebon",       // EC CB 43 2E
    "claraland",      // 03 6E E8 54
    "daniel",         // 73 3F E0 54
    "henry8se",       // 63 A5 E0 54
    "ich",            // E3 C4 E7 54
    "j",              // A3 60 C2 54
    "mail",           // 23 A9 DA 54
    "wax",            // EB 9C 85 1F
    "nathanos",       // 0C FD 0D 2C
    "noahn",          // 33 AC D6 54
    "woojinsagalbi",  // F3 D6 BC 54
    "ronaldo",        // 6C 6D 1F 2C
    "sofia",          // 23 CD D3 54
    "yuinejammin",    // 63 6E E8 54
    "davidoo",        // 3C DC 1A 2C
    "caleb",          // 4C 11 2C 2F
    "elena",          // A7 47 B9 D6
    "emily",          // EC 60 17 2C
    "joshua",         // CA CB D7 3F
    "rebeccarcenter", // AC 78 5F 49
    "richard",        // 8C 10 50 2F
    "edward",         // 5C 6F 10 2C
    "sarahrarang",    // 07 3E A2 D6
    "youn",           // 7C 9C 1D 2C
    "yujin",          // 5C 32 12 2C
    "chris_p_bacon"}; // FC C8 38 2F ##========== 0 to 30 ==========#

int ampm = 0; // 0 am, 1 pm

MFRC522 rfid(SS, RST);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println();
  mlx.begin();
  Serial.println("system is ready to go");
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

  String current_uid = "";
  byte letter;
  for (byte i = 0; i < rfid.uid.size; i++)
  {
    current_uid.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    current_uid.concat(String(rfid.uid.uidByte[i], HEX));
  }

  current_uid.toUpperCase();

  // for (int count = 0; !current_uid.substring(1) == UIDmembers[count]; count++) {
  for (int i = 0; i < 31; i++)
  {
    if (current_uid == UIDmembers[i])
    {
      Serial.print(UIDmembers[i]);
      Serial.print("  ");
      Serial.print(NAMEmembers[i]);
      Serial.println("  ");
      hello(i, ampm);
      tempcheak();
    }
  }
}

void beep()
{
  digitalWrite(buzzerPin, HIGH);
}

void tempcheak()
{
  //   String temp = "";
  //   temp += mlx.readObjectTempC();
  // return 0;
}
void hello(int a, int b) // a : name, b: am,pm 0 = am, 1, = pm
{
  Serial.print("hello ");
  if (b == 0)
  {
    Serial.print(NAMEmembers[a]);
    Serial.println("! good morning");
  }
  if (b == 1)
  {
    Serial.print(NAMEmembers[a]);
    Serial.println("! good afternoon!");
  }
}