#include "../header/cutthroat.h"

CutThroat::CutThroat()
{
    this->spellClass = new string("Rogue");
    this->spellLevelThreshold = 3;
}

void CutThroat::doSpell(StatsManager* sm, Enemy* e)
{
    // do stuff;
}