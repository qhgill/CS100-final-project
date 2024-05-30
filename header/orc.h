#pragma once
#include "enemy.h"
#include "statsManager.h"

class Orc : public Enemy
{
    public:
        Orc();
        virtual void calculateTurn(StatsManager* sm);
};
