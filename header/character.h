#pragma once
#include <string>
#include "./spell.h"
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
        Character(int, int, int, int, string, Spell*, Spell*, Spell*);
        Character();
        int getBaseHP();
        int getBaseDamage();
        int getBasePhysicalResist();
        int getBaseMagicResist();
        string getClassName();
        Spell* getFirstSpell();
        Spell* getSecondSpell();
        Spell* getThirdSpell();
};