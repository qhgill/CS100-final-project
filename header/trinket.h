#include <iostream>
#include <string>
using namespace std;
#include "./item.h"

class Trinket : public Item {
    private:
        int pierce;
    public:
        Trinket(string name, int level, int pierce) : pierce(pierce) {this->name = name; this->level = level;};
        int getPierce() {return pierce;};
        int calcValue() {return pierce*level;};
};