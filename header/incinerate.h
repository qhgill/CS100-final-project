#pragma once
#include "spell.h"

class Incinerate : public Spell
{
    public:
    Incinerate();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};