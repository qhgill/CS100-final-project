#pragma once
#include "spell.h"

class CutThroat : public Spell
{
    public:
    CutThroat();
    void doSpell(int &playerHP, int &playerDamage, int playerLevel, int &playerGold, Enemy*) override;
};