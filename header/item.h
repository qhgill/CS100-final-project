#pragma once
#include <iostream>
using std::string;

class Item {
    protected:
        string name;
        int level;
    public:
        Item();
        Item(string name, int level);
        string getName() {return name;}
        int getLevel() {return level;}
        virtual int calcValue() = 0;
};