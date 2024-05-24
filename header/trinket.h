#pragma once
#include <string>
#include "item.h"
using std::string;

class Trinket : public Item {
    private:
        int pierce;
    public:
        Trinket() : Item("", 0, "trinket"), pierce(0) {};
        Trinket(string name, int level, int pierce) : Item(name, level, "trinket"), pierce(pierce) {};
        int getPierce() {return pierce;};
        int calcValue() {return pierce*level;};
};