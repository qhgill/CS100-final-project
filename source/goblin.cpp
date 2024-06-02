#include "../header/goblin.h"

Goblin::Goblin() : Enemy(2, 15, 15, 5, 5, 5, false, "Goblin") 
{}

void Goblin::calculateTurn(StatsManager* userStats)
{
    //lifesteal with physical attack
    this->healself(3);
    userStats->takeDamage(3, "physical");
    
}