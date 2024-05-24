#pragma once
#include "spell.h"

class Shatter : public Spell
{
    public:
    Shatter();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};