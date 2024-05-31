#include "../header/shatter.h"

Shatter::Shatter()
{
    this->spellClass = new std::string("Shatter");
    this->spellLevelThreshold = 2;
}

void Shatter::doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy* e)
{
         //reduce enemy physical resist by flat amount until end of combat
}