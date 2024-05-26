#include "../header/character.h"
#include <string>

Character::Character(int hp, int dmg, int pr, int mr, std::string cname, Spell* s1, Spell* s2, Spell* s3)
: baseHP(hp), baseDamage(dmg), basePhysicalResist(pr), baseMagicResist(mr), className(cname), firstSpell(s1), secondSpell(s2), thirdSpell(s3)
{}
Character::Character()
: baseHP(10), baseDamage(5), basePhysicalResist(1), baseMagicResist(1), className(""), firstSpell(nullptr), secondSpell(nullptr), thirdSpell(nullptr)
{}
int Character::getBaseHP()
{
    return baseHP;
}
int Character::getBaseDamage()
{
    return baseDamage;
}
int Character::getBasePhysicalResist()
{
    return basePhysicalResist;
}
int Character::getBaseMagicResist()
{
    return baseMagicResist;
}
std::string Character::getClassName()
{
    return className;
}
Spell* Character::getFirstSpell()
{
    return firstSpell;
}
Spell* Character::getSecondSpell()
{
    return secondSpell;
}
Spell* Character::getThirdSpell()
{
    return thirdSpell;
}