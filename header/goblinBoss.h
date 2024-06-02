#pragma once
#include "boss.h"

class GoblinBoss: public Boss
{
    public:
        GoblinBoss();
        void calculatePhaseOneTurn(StatsManager*);
        void calculatePhaseTwoTurn(StatsManager*);
        void calculateTurn(StatsManager*);
};