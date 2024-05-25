#pragma once
#include <string>
#include "enemy.h"
//#include "statsManager.h"

class Spell 
{
    protected:
        std::string* spellClass;
        int spellLevelThreshold;
    public:
        Spell();
        Spell(const std::string& sc, int slt);
        ~Spell();
        std::string getSpellClass() const;
        int getSpellLevelThreshold() const;
        //virtual void doSpell(StatsManager*, Enemy*) = 0;
};