#pragma once
#include <string>
#include "./statsManager.h"
#include "./enemy.h"

class Spell {
    private:
        std::string* spellClass;
        int spellLevelThreshold;
    public:
        Spell();
        Spell(const std::string& sc, int slt);

        ~Spell();

        std::string getSpellClass() const;
        int getSpellLevelThreshold() const;

        virtual void doSpell(StatsManager*, Enemy*) = 0;
};