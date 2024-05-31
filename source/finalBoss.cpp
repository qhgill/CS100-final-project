#include "../header/finalBoss.h"

FinalBoss::FinalBoss() : Boss(0, 0, 0, 0, 0, 0, false, "")
{}

FinalBoss::FinalBoss() : Boss(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isdead, const std::string& name)
: Boss(level, health, maxHealth, damage, magicResist, physicalResist, isDead, name)
{}

void FinalBoss::calculateTurn(StatsManager* sm) {
    double healthPercent = (getHealth()*1.0) / getMaxHealth();

    if (healthPercent > 0.5) {
        calculatePhaseOneTurn(sm);
    } else {
        calculatePhaseTwoTurn(sm);
    }
}

void FinalBoss::calculatePhaseOneTurn(StatsManager* sm) 
{
    int joeDamage = getDamage();

    if (sm->getMagicResist() > sm->getPhysicalResist()) {
        sm->takeDamage(joeDamage, "physical");
    } else {
        sm->takeDamage(joeDamage, "magical");
    }
};

void FinalBoss::calculatePhaseTwoTurn(StatsManager* sm) 
{
    int joeDamage = getDamage();

    if (sm->getMagicResist() > sm->getPhysicalResist()) {
        joeDamage *= 2;
        sm->takeDamage(joeDamage, "physical"); //one big attack
    } else {
        for (unsigned i = 0; i < 3; i++) {
            sm->takeDamage(joeDamage, "magical"); //three smaller attacks (magical resist applies on all)
        }
    }
};