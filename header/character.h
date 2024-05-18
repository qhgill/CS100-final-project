#pragma once
#include <string>
#include "spell.h"
using std::string;

class Character {
    protected:
        int baseHP;
        int baseDamage;
        int basePhysicalResist;
        int baseMagicResist;
        string className;
        Spell* firstSpell;
        Spell* secondSpell;
        Spell* thirdSpell;
    public:
        Character();
        Character(int hp, int dmg, int pr, int mr, string cname, Spell* s1, Spell* s2, Spell* s3);
        int getBaseHP();
        int getBaseDamage();
        int getBasePhysicalResist();
        int getBaseMagicResist();
        string getClassName();
        Spell* getFirstSpell();
        Spell* getSecondSpell();
        Spell* getThirdSpell();
};