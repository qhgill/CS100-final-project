#pragma once
#include "./boss.h"

class BossPart2 : public Boss
{
    public:
        BossPart2(); 
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};