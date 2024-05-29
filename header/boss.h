#pragma once
#include "./enemy.h"
#include "./statsManager.h"

class Boss : public Enemy
{
    public:
        Boss();
        Boss(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name);

        void calculateTurn(StatsManager*) override {};
        virtual void calculatePhaseOneTurn(StatsManager*) = 0;
        virtual void calculatePhaseTwoTurn(StatsManager*) = 0;
};