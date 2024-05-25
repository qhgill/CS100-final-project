#pragma once
#include "./boss.h"

class BossPart1 : public Boss 
{
    public:
        BossPart1();
        virtual void calculatephase1turn(StatsManager*) {return;};
        virtual void calculatephase2turn(StatsManager*) {return;};
};