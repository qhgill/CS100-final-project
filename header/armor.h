#pragma once
#include <string>
#include "item.h"
using std::string;

class Armor : public Item {
    private:
        int health;
        int phyRes;
        int magRes;
    public:
        Armor() : Item("", 0, "armor"), health(0), phyRes(0), magRes(0) {};
        Armor(string name, int level, int health, int phyRes, int magRes) : Item(name, level, "armor"), health(health), phyRes(phyRes), magRes(magRes) {};
        int getHealth() {return health;};
        int getPhyRes() {return phyRes;};
        int getMagRes() {return magRes;};

        int calcValue() {return 0;}; //temporary
        int calcPhyDamage(int damageRecieved) {
            int calcDamage = (damageRecieved - (level*phyRes*0.1));
            if (calcDamage < 0) {calcDamage = 0;}

            return calcDamage;
            
        };
        int calcMagDamage(int damageRecieved) {
            int calcDamage = (damageRecieved - (level*magRes*0.1));
            if (calcDamage < 0) {calcDamage = 0;}

            return calcDamage;
        };
};