#include "../header/goblinBoss.h"

GoblinBoss::GoblinBoss() : Boss(5, 60, 60, 5, 10, 15, false, "Commander Joe")
{
    powerUp = false;
}

//int level, int health, int maxHealth, int damage,
//int magicResist, int physicalResist, bool isDead
//string name

void GoblinBoss::calculateTurn(StatsManager* statsManager)
{
    if (this->getHealth() <= (this->getMaxHealth()/2))
    {
        powerUp = true;
    }

    if(powerUp == false)
    {
        calculatePhaseOneTurn(statsManager);
    }
    
    if(powerUp == true)
    {
        calculatePhaseTwoTurn(statsManager);
    }
}

void GoblinBoss::calculatePhaseOneTurn(StatsManager* userStats)
{
    
    userStats->takeDamage(this->getDamage(), "physical");
    this->healself(this->getDamage());
    
    userStats->takeDamage(this->getDamage(), "magical");
    this->healself(this->getDamage());
    
    if(this->getHealth() > this->getMaxHealth())
    {
        this->dealDamage(this->getHealth() - this->getMaxHealth());
        //sets current health to maxhealth
    }
    
}   

void GoblinBoss::calculatePhaseTwoTurn(StatsManager* userStats)
{   
    if(this->getHealth() > 5)
    {
        userStats->takeDamage(this->getDamage()*2, "physical");
        this->healself(this->getDamage()*2);

        userStats->takeDamage(this->getDamage()*2, "magical");
        this->healself(this->getDamage()*2);
    }
    else if(this->getHealth() <= 5)
    {
        userStats->reducePR(userStats->getCurrentPR());
        userStats->reduceMR(userStats->getCurrentMR());
        userStats->takeDamage(this->getDamage()*10, "physical");
        this->healself(this->getDamage()*10);
    }
    
    if(this->getHealth() > this->getMaxHealth())
    {
        this->dealDamage(this->getHealth() - this->getMaxHealth());
        //sets current health to maxhealth
    }

}
