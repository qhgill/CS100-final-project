#pragma once
#include "./boss.h"

class BossPart3 : public Boss
{
    public:
        BossPart3(); 
        virtual void calculatephase1turn(StatsManager*);
        virtual void calculatephase2turn(StatsManager*);
};