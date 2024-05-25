#pragma once
#include <string>
#include "item.h"

class Weapon: public Item
{
    private:
        int damage;
        std::string damageType;
    public:
        Weapon();
        Weapon( const std::string& name, int level, int damage_, const std::string& damageType_ );
        int getDamage();
        std::string getDamageType();
        int calcDamage(int lvl);
        virtual int calcValue();
};
