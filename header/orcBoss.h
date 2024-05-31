#pragma once
#include "boss.h"

class OrcBoss : public Boss
{
    public:
        OrcBoss(); 
        void calculatePhaseOneTurn(StatsManager*);
        void calculatePhaseTwoTurn(StatsManager*);
        void calculateTurn(StatsManager*);
};