#include "../header/lifeLeech.h"

LifeLeech::LifeLeech()
{
    this->spellClass = new string("LifeLeech");
    this->spellLevelThreshold = 2;
}

void LifeLeech::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int level = e->getLevel();
         e->dealDamage(10/level);
         playerHP += (10/level);
         //deal flat magic damage and heal for the same amount based on level
}