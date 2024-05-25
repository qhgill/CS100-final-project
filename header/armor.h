#pragma once
#include <string>
#include "item.h"

class Armor : public Item 
{
    private:
        int health;
        int phyRes;
        int magRes;
    public:
        Armor();
        Armor(std::string name, int level, int health, int phyRes, int magRes);
        
        int getHealth();
        int getPhyRes();
        int getMagRes();
        
        int calcValue();
        int calcPhyDamage(int damageRecieved);
        int calcMagDamage(int damageRecieved);
};