#include "../header/pirateBoss.h"

using namespace std;

PirateBoss::PirateBoss() : Boss() {};

PirateBoss::PirateBoss(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name)
: Boss(level, health, maxHealth, damage, magicResist, physicalResist, isDead, name) {};


void PirateBoss::calculateTurn(StatsManager* sm) {
    double healthPercent = (getHealth() * 1.0) / getMaxHealth();

    if (healthPercent >= 0.5) { //phase one if 50% or more of health
        calculatePhaseOneTurn(sm);
    } else {                    //phase two otherwise
        calculatePhaseTwoTurn(sm);
    }
}


void PirateBoss::calculatePhaseOneTurn(StatsManager* sm) 
{
    int pirateDamage = getDamage();
    sm->takeDamage(pirateDamage, "physical");
    return;
};

void PirateBoss::calculatePhaseTwoTurn(StatsManager* sm) 
{
    int pirateDamage = getDamage() * 1.5; // maybe increase damage based off of player gold
    sm->takeDamage(pirateDamage, "physical");
    return;
};