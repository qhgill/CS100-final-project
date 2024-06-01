#include "../header/spell.h"

Spell::Spell(): spellClass(""), spellLevelThreshold(-1) {}

Spell::Spell(const std::string& sc, int slt): spellClass(sc), spellLevelThreshold(slt){}


std::string Spell::getSpellClass() const
{
    return spellClass;
}

int Spell::getSpellLevelThreshold() const
{
    return this->spellLevelThreshold;
}