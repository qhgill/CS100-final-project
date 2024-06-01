#pragma once
#include <string>
#include "spell.h"

class Character 
{
    protected:
        int baseHP;
        int baseDamage;
        int basePhysicalResist;
        int baseMagicResist;
        std::string className;
        Spell* firstSpell;
        Spell* secondSpell;
        Spell* thirdSpell;
    public:
        Character();
        Character(int hp, int dmg, int pr, int mr, std::string cname, Spell* s1, Spell* s2, Spell* s3);
        ~Character();
        Character(Character&) = delete;
        Character operator=(Character&) = delete;
        int getBaseHP();
        int getBaseDamage();
        int getBasePhysicalResist();
        int getBaseMagicResist();
        std::string getClassName();
        Spell* getFirstSpell();
        Spell* getSecondSpell();
        Spell* getThirdSpell();
};