#include "../header/bludgeon.h"

Bludgeon::Bludgeon()
{
    this->spellClass = new std::string("Bludgeon");
    this->spellLevelThreshold = 3;
}

void Bludgeon::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int overallDamage = playerDamage;
         if ((e->getHealth() * 100) > ((e->getMaxHealth() * 100)-(e->getMaxHealth() * 20))){
            e->dealDamage((10/overallDamage)*2);
         } else {
            e->dealDamage(10/overallDamage);
         }
         
         //deal flat physical damage based on the player's overall damage, double this damage if the enemy is above a certain hp(80%?)
}