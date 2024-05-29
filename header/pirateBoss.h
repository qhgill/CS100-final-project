#pragma once
#include "./boss.h"

class PirateBoss : public Boss
{
    public:
        PirateBoss(); 
        PirateBoss(int, int, int, int, int, int, bool, const std::string&);

        virtual void calculateTurn(StatsManager*);
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};