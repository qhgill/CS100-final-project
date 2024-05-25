#pragma once
#include "./boss.h"

class BossPart2 : public Boss
{
    public:
        BossPart2(); 
        virtual void calculatephase1turn(StatsManager*);
        virtual void calculatephase2turn(StatsManager*);
};