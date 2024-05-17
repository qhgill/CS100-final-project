#include "../header/spell.h"

Spell::Spell()
{
    this->spellClass = new std::string("");
    this->spellLevelThreshold = -1;
}

Spell::Spell(const std::string& sc, int slt)
{
    this->spellClass = new std::string(sc);
    this->spellLevelThreshold = slt;
}

Spell::~Spell()
{
    delete this->spellClass;
}

std::string Spell::getSpellClass() const
{
    return *spellClass;
}

int Spell::getSpellLevelThreshold() const
{
    return this->spellLevelThreshold;
}