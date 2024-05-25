#pragma once
#include "./boss.h"

class BossPart2 : public Boss
{
    public:
        virtual void calculatephase1turn(StatsManager*) {return;};
        virtual void calculatephase2turn(StatsManager*) {return;};
};