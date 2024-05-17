#include "../header/pickpocket.h"

PickPocket::PickPocket()
{
    this->spellClass = new string("Rogue");
    this->spellLevelThreshold = 2;
}

void PickPocket::doSpell(StatsManager* sm, Enemy* e)
{
    // do stuff;
}