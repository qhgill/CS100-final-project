#pragma once
#include <string>
#include "item.h"

class Weapon: public Item
{
    private:
        int damage;
        std::string damageType;
    public:
        Weapon(): damage(0), damageType("physical"), Item("a", 0, "weapon") {}
        Weapon( std::string name, int level, int damage_, std::string damageType_ );
        int getDamage() { return damage; }
        std::string getDamageType() { return damageType; }
        int calcDamage(int lvl) { return lvl*damage; }
        virtual int calcValue() { return 0; }
};
