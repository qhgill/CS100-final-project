#pragma once

class EncounterManager
{
    private:
        int encounterCount;
    public:
        EncounterManager();
        EncounterManager(int currCount);
        int getEncounterCount();
        void resetEncounterCount();
        void incrementEncounterCount();
};