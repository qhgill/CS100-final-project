#pragma once
#include <iostream>
#include <string>
#include "item.h"
using namespace std;

class Weapon: public Item
{
    private:
        int damage;
        string damageType;

    public:
        Weapon() : damage(0), damageType(""), Item("", 0) {}
        Weapon(int damage_, string damageType_, string name, int level);
        int getDamage() {return damage;}
        string getDamageType() {return damageType;}
        int calcDamage(int level) {return level*damage;}
        int calcValue() {return 0;}
};
