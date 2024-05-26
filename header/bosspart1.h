#pragma once
#include "./boss.h"

class BossPart1 : public Boss 
{
    public:
        BossPart1();
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};