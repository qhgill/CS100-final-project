#include "../header/arcaneBlast.h"

ArcaneBlast::ArcaneBlast()
{
    this->spellClass = new string("ArcaneBlast");
    this->spellLevelThreshold = 1;
}

void ArcaneBlast::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         int level = playerLevel;
         e->dealDamage(10/level);
         //deal flat magic damage based on level
}