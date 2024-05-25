#pragma once
#include "./boss.h"

class BossPart4 : public Boss 
{
    public:
        BossPart4();
        virtual void calculatephase1turn(StatsManager*);
        virtual void calculatephase2turn(StatsManager*);
};