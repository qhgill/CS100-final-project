#include "../header/cutthroat.h"

CutThroat::CutThroat()
{
    this->spellClass = new std::string("Cutthroat");
    this->spellLevelThreshold = 3;
}

void CutThroat::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int level = playerLevel;
         e->dealDamage(10/level);
         //deal physical and magic damage based on level and ignore resistances
}