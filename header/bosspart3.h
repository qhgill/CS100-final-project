#pragma once
#include "./boss.h"

class BossPart3 : public Boss
{
    public:
        BossPart3(); 
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};