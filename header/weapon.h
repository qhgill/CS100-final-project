#include <iostream>
#include <string>
using namespace std;
#include "header/item.h"

class weapon: public item
{
    private:
        int damage;
        string damageType;
        string weaponName;

    public:
        weapon(int damage_, string damageType_, string weaponName_);
        int getDamage() {return damage;}
        string getDamageType() {return damageType;}
        string getWeaponName() {return weaponName;}
        int calcDamage(int level) {return level*damage;}

};