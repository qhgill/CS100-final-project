#include "../header/orc.h"

Orc::Orc()
: Enemy(3, 60, 60, 8, 3, 8, false, "Orc")
{}

Orc::Orc(int level)
: Enemy(level, level*20, level*20, level*3, 3, 8, false, "Orc")
{}

void Orc::calculateTurn(StatsManager* sm)
{
    // orc's physical intimidation cracks character's physical resistance
    sm->reducePR(2);
    sm->takeDamage(this->getDamage()*this->getLevel(), "physical");
}