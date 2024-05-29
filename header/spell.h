#pragma once
#include <string>

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

        virtual void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) = 0;
};
