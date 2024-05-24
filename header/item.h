#pragma once
#include <iostream>
using std::string;

class Item {
    protected:
        string name;
        string itemType;
        int level;
    public:
        Item();
        Item(string name, int level, string type);
        string getName() {return name;}
        int getLevel() {return level;}
        string getType() {return itemType;}
        virtual int calcValue() = 0;
};