#include "../header/mage.h"

Mage::Mage() 
: Character(7, 7, 1, 1, "Mage", new LifeLeech(), new Incinerate(), new ArcaneBlast()) 
{}
Mage::Mage(int hp, int dmg, int pr, int mr, std::string cname, Spell* s1, Spell* s2, Spell* s3) 
: Character(hp, dmg, pr, mr, cname, s1, s2, s3) 
{}
