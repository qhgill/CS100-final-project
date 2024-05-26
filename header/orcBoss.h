#pragma once
#include "boss.h"

class OrcBoss : public Boss
{
    public:
        OrcBoss(); 
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};