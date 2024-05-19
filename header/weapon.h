#pragma once
#include <string>
#include "item.h"
using std::string;

class Weapon: public Item
{
    private:
        int damage;
        string damageType;
    public:
        Weapon(): damage(0), damageType(0), Item("", 0) {}
        Weapon( string name, int level, int damage_, string damageType_ );
        int getDamage() { return damage; }
        string getDamageType() { return damageType; }
        int calcDamage(int lvl) { return lvl*damage; }
        virtual int calcValue() { return 0; }
};
