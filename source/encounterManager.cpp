#include "../header/encounterManager.h"

EncounterManager::EncounterManager() 
: encounterCount(0) 
{}
EncounterManager::EncounterManager(int currCount)
: encounterCount(currCount) 
{}
int EncounterManager::getEncounterCount() 
{ 
    return encounterCount; 
}
void EncounterManager::resetEncounterCount() 
{ 
    encounterCount = 0; 
}
void EncounterManager::incrementEncounterCount() 
{ 
    encounterCount++; 
}