#include "../header/armor.h"

Armor::Armor() 
: Item("a", 0, "armor"), health(0), phyRes(0), magRes(0) 
{}

Armor::Armor(std::string name, int level, int health, int phyRes, int magRes) 
: Item(name, level, "armor"), health(health), phyRes(phyRes), magRes(magRes) 
{}

int Armor::getHealth() 
{
    return health;
}

int Armor::getPhyRes() 
{
    return phyRes;
}

int Armor::getMagRes() 
{
    return magRes;
}

int Armor::calcValue() 
{
    return 0; //temporary
}

int Armor::calcPhyDamage(int damageRecieved) 
{
    int calcDamage = (damageRecieved - (level*phyRes*0.1));
    if (calcDamage < 0) 
    {
        calcDamage = 0;
    }

    return calcDamage;
}

int Armor::calcMagDamage(int damageRecieved) 
{
    int calcDamage = (damageRecieved - (level*magRes*0.1));
    if (calcDamage < 0) 
    {
        calcDamage = 0;
    }

    return calcDamage;
}