#include "../header/backstab.h"

BackStab::BackStab()
{
    this->spellClass = new std::string("Backstab");
    this->spellLevelThreshold = 1;
}

void BackStab::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int overallDamage = playerDamage;
         e->dealDamage(10/overallDamage);
         //deal flat physical damage based on overall damage
}