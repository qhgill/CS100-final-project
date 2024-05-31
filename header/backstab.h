#pragma once
#include "spell.h"

class BackStab : public Spell
{
    public:
    BackStab();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};