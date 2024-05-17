#include "../header/backstab.h"

BackStab::BackStab()
{
    this->spellClass = new string("Rogue");
    this->spellLevelThreshold = 1;
}

void BackStab::doSpell(StatsManager* sm, Enemy* e)
{
    // do stuff;
}