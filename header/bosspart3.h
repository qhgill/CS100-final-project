#pragma once
#include "./boss.h"

class BossPart3 : public Boss
{
    public:
        virtual void calculatephase1turn(StatsManager*) {return;};
        virtual void calculatephase2turn(StatsManager*) {return;};
};