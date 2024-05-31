#include "../header/orcBoss.h"

OrcBoss::OrcBoss() 
: Boss(8, 100, 100, 21, 3, 14, false, "General Bob")
{}

void OrcBoss::calculateTurn(StatsManager* statsManager){
    //
}

void OrcBoss::calculatePhaseOneTurn(StatsManager* statsManager) 
{
    // Move 1a
    int damage = this->getDamage();
    statsManager->takeDamage(damage, "physical");
    
    // Move 1b
    int specialMoveEffect = 5;
    statsManager->reducePR(specialMoveEffect);
    return;
}

void OrcBoss::calculatePhaseTwoTurn(StatsManager* statsManager) 
{
    // Move 2a
    int powerfulDamage = this->getDamage() * 2;
    statsManager->takeDamage(powerfulDamage, "physical");
    
    // Move 2b
    int resistanceReduction = 10;
    statsManager->reducePR(resistanceReduction);
    statsManager->reduceMR(resistanceReduction);

    return;
}