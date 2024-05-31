#include "../header/incinerate.h"

Incinerate::Incinerate()
{
    this->spellClass = new std::string("Incinerate");
    this->spellLevelThreshold = 3;
}

void Incinerate::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int overallDamage = playerDamage;
         if ((e->getHealth() * 100) > ((e->getMaxHealth() * 100)-(e->getMaxHealth() * 80))){
            e->dealDamage((10/overallDamage)*2);
         } else {
            e->dealDamage(10/overallDamage);
         }
         //deal flat magic damage based on overall damage, if enemy is below a certain hp(20%?), double this damage
}