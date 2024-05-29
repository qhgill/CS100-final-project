#pragma once
#include <string>

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
};
