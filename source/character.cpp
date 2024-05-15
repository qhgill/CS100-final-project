#include "./character.h"
#include <string>
using std::string;

Character::Character(int hp, int dmg, int pr, int mr, string cname, Spell* s1, Spell* s2, Spell* s3): baseHP(hp), baseDamage(dmg), basePhysicalResist(pr), baseMagicResist(mr), className(cname), firstSpell(s1), secondSpell(s2), thirdSpell(s3){}
Character::Character(): baseHP(10), baseDamage(5), basePhysicalResist(1), baseMagicResist(1), className(""), firstSpell(nullptr), secondSpell(nullptr), thirdSpell(nullptr){}
int Character::getBaseHP(){
    return baseHP;
}
int Character::getBaseDamage(){
    return baseDamage;
}
int Character::getBasePhysicalResist(){
    return basePhysicalResist;
}
int Character::getBaseMagicResist(){
    return baseMagicResist;
}
string Character::getClassName(){
    return className;
}
void Character::useSpell(Spell* spellToUse){
    spellToUse->doSpell();
}