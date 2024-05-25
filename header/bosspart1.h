#pragma once
#include "./boss.h"

class BossPart1 : public Boss 
{
    public:
        BossPart1();
        virtual void calculatephase1turn(StatsManager*);
        virtual void calculatephase2turn(StatsManager*);
};