#pragma once
#include <iostream>
#include <string> 
using namespace std;

class EncounterManager
{
    private:
        int encounterCount;

    public:
        EncounterManager() : encounterCount(0) {}
        EncounterManager(int currCount) : encounterCount(currCount) {}

        int getEncounterCount() { return encounterCount; }
        void resetEncounterCount() { encounterCount = 0; }
        void incrementEncounterCount() { encounterCount++; }
};