#pragma once
#include "enemy.h"
#include "statsManager.h"

class Orc : public Enemy
{
    public:
        Orc();
        Orc(int level);
        virtual void calculateTurn(StatsManager* sm);
};
