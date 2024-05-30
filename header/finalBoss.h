#pragma once
#include "./boss.h"

class FinalBoss : public Boss 
{
    public:
        FinalBoss();
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};