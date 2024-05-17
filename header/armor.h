#include <iostream>
#include <string>
using namespace std;
#include "./item.h"

class Armor : public Item {
    private:
        int health;
        int phyRes;
        int magRes;
    public:
        Armor(string name, int level, int health, int phyRes, int magRes) : health(health), phyRes(phyRes), magRes(magRes) {this->name = name; this->level = level;};
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