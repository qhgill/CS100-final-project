#pragma once
#include "./enemy.h"
#include "./statsManager.h"

class Boss : public Enemy
{
    public:
        Boss() : Enemy(0, 0, 0, 0, 0, 0, false, "") {};
        virtual void calculatephase1turn(StatsManager*) = 0;
        virtual void calculatephase2turn(StatsManager*) = 0;
};