#pragma once
#include "enemy.h"
#include "statsManager.h"

class Goblin : public Enemy
{
    public:
        Goblin();
        virtual void calculateTurn(StatsManager*);
};