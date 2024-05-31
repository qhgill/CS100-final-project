#pragma once
#include "./boss.h"

class FinalBoss : public Boss 
{
    public:
        FinalBoss();
        FinalBoss(int, int, int, int, int, int, bool, const std::string& name);


        void calculateTurn(StatsManager*);
        virtual void calculatePhaseOneTurn(StatsManager*);
        virtual void calculatePhaseTwoTurn(StatsManager*);
};