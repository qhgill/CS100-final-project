#pragma once
#include "spell.h"

class Bludgeon : public Spell
{
    public:
    Bludgeon();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};