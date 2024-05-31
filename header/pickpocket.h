#pragma once
#include "spell.h"

class PickPocket : public Spell
{
    public:
    PickPocket();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};
