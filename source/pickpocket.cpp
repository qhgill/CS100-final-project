#include "../header/pickpocket.h"

PickPocket::PickPocket()
{
    this->spellClass = new string("Rogue");
    this->spellLevelThreshold = 2;
}

void PickPocket::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int level = e->getLevel();
         e->dealDamage(3);
         playerGold += (10/level);
         //deal a low amount of physical damage and increase gold by a flat amount based on level
}