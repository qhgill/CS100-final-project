#pragma once
#include "enemy.h"
#include "statsManager.h"

class Goblin : public Enemy
{
    public:
        Goblin();
        Goblin(int level);
        virtual void calculateTurn(StatsManager*);
};