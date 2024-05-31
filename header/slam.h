#pragma once
#include "spell.h"

class Slam : public Spell
{
    public:
    Slam();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};