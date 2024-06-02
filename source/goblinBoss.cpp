#include "../header/goblinBoss.h"

GoblinBoss::GoblinBoss() : Boss(5, 60, 60, 12, 10, 15, false, "Commander Joe")
{}

//int level, int health, int maxHealth, int damage,
//int magicResist, int physicalResist, bool isDead
//string name

void GoblinBoss::calculateTurn(StatsManager* statsManager){
    //
}

void GoblinBoss::calculatePhaseOneTurn(StatsManager* userStats)
{
    
    userStats->takeDamage(5, "physical");
    this->healself(5);
    
    userStats->takeDamage(5, "magical");
    this->healself(5);
    
    if(this->getHealth() > this->getMaxHealth())
    {
        this->dealDamage(this->getHealth() - this->getMaxHealth());
        //sets current health to maxhealth
    }
    
}   

void GoblinBoss::calculatePhaseTwoTurn(StatsManager* userStats)
{
    if(this->getHealth() <= 5)
    {
        userStats->reducePR(userStats->getCurrentPR());
        userStats->reduceMR(userStats->getCurrentMR());
        userStats->takeDamage(50, "physical");
        this->healself(50);
    }
    else
    {
        userStats->takeDamage(10, "physical");
        this->healself(10);

        userStats->takeDamage(10, "magical");
        this->healself(10);
    }

    
    if(this->getHealth() > this->getMaxHealth())
    {
        this->dealDamage(this->getHealth() - this->getMaxHealth());
        //sets current health to maxhealth
    }

}
