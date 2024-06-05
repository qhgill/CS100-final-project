#include "../header/goblin.h"

Goblin::Goblin() : Enemy(2, 15, 15, 3, 5, 5, false, "Goblin") 
{}

void Goblin::calculateTurn(StatsManager* userStats)
{
    //lifesteal with physical attack
    this->healself(this->getDamage());
    userStats->takeDamage(this->getDamage(), "physical");

    if(this->getHealth() > this->getMaxHealth())
    {
        this->dealDamage(this->getHealth() - this->getMaxHealth());
        //sets current health to maxhealth
    }
    
}