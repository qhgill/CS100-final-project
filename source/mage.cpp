#include "./mage.h"
#include "./lifeleech.h"
#include "./incinerate.h"
#include "./arcaneBlast.h"
#include <string>
using std::string;

Mage::Mage(int hp, int dmg, int pr, int mr, string cname, spell* s1, spell* s2, spell* s3) : Character(hp, dmg, pr, mr, cname, s1, s2, s3) {}
Mage::Mage() :
    Character(7, 7, 1, 1, "Mage", new lifeleech, new incinerate, new arcaneBlast) {}
