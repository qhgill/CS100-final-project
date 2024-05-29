#include "../header/slam.h"

Slam::Slam()
{
    this->spellClass = new string("Slam");
    this->spellLevelThreshold = 1;
}

void Slam::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int level = e->getLevel();
         e->dealDamage(10/level);
         //deal flat physical damage based on level
}