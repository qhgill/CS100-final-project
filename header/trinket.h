#pragma once
#include <string>
#include "item.h"
using std::string;

class Trinket : public Item {
    private:
        int pierce;
    public:
        Trinket() : Item("", 0), pierce(0) {};
        Trinket(string name, int level, int pierce) : pierce(pierce) {this->name = name; this->level = level;};
        int getPierce() {return pierce;};
        int calcValue() {return pierce*level;};
};