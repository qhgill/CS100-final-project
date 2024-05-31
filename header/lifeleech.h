#pragma once
#include "spell.h"

class LifeLeech : public Spell
{
    public:
    LifeLeech();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};