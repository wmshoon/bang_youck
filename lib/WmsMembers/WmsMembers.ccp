#include "Arduino.h"
#include "WmsMembers.h"

// define as "member number"
//  *undefined equals that the modules are not delivered yet.
#define _dummy "asdfasdfasd"
// private card
#define MASTER_DAVIDOO "undefined"
#define MASTER_RONALDO "CA CB D7 3F"
#define MASTER_JAIL "00 44 11 5C"
#define MASTER_NATHANOS "39 48 62 28"
// private card
#define _aylinux "udefined"
#define _alicebon "udefined"
#define _claraland "undefined"
#define _danielephant "udefined"
#define _henry8se "udefined"
#define _ichibab "udefined" //임채환
#define _jail "undefined"
#define _liamail "undefined"
#define _maxrange "udefined"
#define _nathanos "udefined"
#define _noahn "udefined"
#define _woojinsagalbi "udefined"
#define _ronaldo "undefined"
#define _sofiannapurna "udefined"
#define _yuniejjajang "udefined"

// ending of student
#define _davidoo "undefined"
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
int master[4] = {
    _dummy,          //    0
    MASTER_DAVIDOO,  //    1
    MASTER_JAIL,     //    2
    MASTER_NATHANOS, //    3
    MASTER_RONALDO}; //    4
int members[28] = {
    _dummy,         //    0
    _aylinux,       //    1
    _alicebon,      //    2
    _claraland,     //    3
    _danielephant,  //    4
    _henry8se,      //    5
    _ichibab,       //    6
    _jail,          //    7
    _liamail,       //    8
    _maxrange,      //    9
    _nathanos,      //    10
    _noahn,         //    11
    _woojinsagalbi, //    12
    _ronaldo,       //    13
    _sofiannapurna, //    14
    _yuniejjajang,  //    15

    _davidoo, //    16
    _caleb,   //    17
    _chris,   //    18
    _edward,  //    19
    _elena,   //    20
    _emily,   //    21
    _joshua,  //    22
    _rebecca, //    23
    _richard, //    24
    _sarah,   //    25
    _youn,    //    26
    _yujin};  //    27
}

int member(int a) { return member[a] }
int master(int a) { return master[a] }