#include "./warrior.h"
#include "./bludgeon.h"
#include "./shatter.h"
#include "./slam.h"
#include <string>
using std::string;

Warrior::Warrior(int hp, int dmg, int pr, int mr, string cname, spell* s1, spell* s2, spell* s3) : Character(hp, dmg, pr, mr, cname, s1, s2, s3) {}
Warrior::Warrior() :
    Character(15, 3, 1, 1, "Warrior", new bludgeon, new shatter, new slam) {}
