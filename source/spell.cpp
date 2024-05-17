#include "../header/spell.h"

//Constructor
Spell::Spell()
{
    spellClass = new std::string("");
    spellLevelThreshold = -1;
}

Spell::Spell(const std::string& sc, int slt)
{
    spellClass = new std::string(sc);
    spellLevelThreshold = slt;
}

Spell::~Spell()
{
    delete spellClass;
}

std::string Spell::getSpellClass() const
{
    return *spellClass;
}

int Spell::getSpellLevelThreshold() const
{
    return spellLevelThreshold;
}

void Spell::setSpellClass(const std::string& sc)
{
    *spellClass = sc;
}

void Spell::setSpellLevelThreshold(int slt)
{
    spellLevelThreshold = slt;
}
