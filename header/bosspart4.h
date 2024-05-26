#pragma once
#include "./boss.h"

class BossPart4 : public Boss 
{
    public:
        BossPart4();
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};