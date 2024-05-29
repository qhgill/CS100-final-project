#include "../header/spell.h"

Spell::Spell()
{
    this->spellClass = "";
    this->spellLevelThreshold = -1;
}

Spell::Spell(const std::string& sc, int slt)
{
    this->spellClass = sc;
    this->spellLevelThreshold = slt;
}


std::string Spell::getSpellClass() const
{
    return spellClass;
}

int Spell::getSpellLevelThreshold() const
{
    return this->spellLevelThreshold;
}