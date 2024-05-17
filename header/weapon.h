#include <iostream>
#include <string>
using namespace std;
#include "./item.h"

class Weapon: public Item
{
    private:
        int damage;
        string damageType;
        string weaponName;

    public:
        Weapon(int damage_, string damageType_, string weaponName_);
        int getDamage() {return damage;}
        string getDamageType() {return damageType;}
        string getWeaponName() {return weaponName;}
        int calcDamage(int level) {return level*damage;}

};