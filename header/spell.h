#pragma once
#include <string>

#include "enemy.h"

class Spell 
{
    protected:
        std::string spellClass;
        int spellLevelThreshold;
    public:
        Spell();
        Spell(const std::string& sc, int slt);
        std::string getSpellClass() const;
        int getSpellLevelThreshold() const;

        virtual void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) = 0;
};
