#include "Arduino.h"
#include "WmsMembers.h"

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
    "MD",       // 83 9E E0 54
    "MR",       // 83 A8 91 06
    "MJ",       // 00 44 11 5C
    "MN",       // 39 48 62 28
    "Aylin",    // F3 E0 D2 54
    "Alice",    // EC CB 43 2E
    "Clara",    // 03 6E E8 54
    "Daniel",   // 73 3F E0 54
    "Henry",    // 63 A5 E0 54
    "Danielim", // E3 C4 E7 54
    "J",        // A3 60 C2 54
    "Liam",     // 23 A9 DA 54
    "Max",      // EB 9C 85 1F
    "Nathan",   // 0C FD 0D 2C
    "Noah",     // 33 AC D6 54
    "Woojin",   // F3 D6 BC 54
    "Ron",      // 6C 6D 1F 2C
    "Sofia",    // 23 CD D3 54
    "Yunie",    // 63 6E E8 54
    "David",    // 3C DC 1A 2C
    "Caleb",    // 4C 11 2C 2F
    "Elena",    // A7 47 B9 D6
    "Emily",    // EC 60 17 2C
    "Joshua",   // CA CB D7 3F
    "Rebecca",  // AC 78 5F 49
    "Richard",  // 8C 10 50 2F
    "Edward",   // 5C 6F 10 2C
    "Sarah",    // 07 3E A2 D6
    "Youn",     // 7C 9C 1D 2C
    "Yujin",    // 5C 32 12 2C
    "Chris"};   // FC C8 38 2F ##========== 0 to 30 ==========#

int UIDof(char a)
{
    while (int i = 0; i > 30; i++)
    {
        if (a == UIDmembers(i))
        {
            return UIDmembers(i);
        }
    }
}
int NAMEof(char a))
{
    while (int i = 0; i > 30; i++)
    {
        if (a == NAMEmembers(i))
        {
            return NAMEmembers(i);
        }
    }
}
