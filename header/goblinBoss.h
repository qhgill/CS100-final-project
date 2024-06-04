#pragma once
#include "boss.h"

class GoblinBoss: public Boss
{
    private:
        bool powerUp;
    public:
        GoblinBoss();
        void calculatePhaseOneTurn(StatsManager*);
        void calculatePhaseTwoTurn(StatsManager*);
        void calculateTurn(StatsManager*);

};