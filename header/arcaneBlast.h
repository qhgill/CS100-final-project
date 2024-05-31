#pragma once
#include "spell.h"

class ArcaneBlast : public Spell
{
    public:
    ArcaneBlast();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};